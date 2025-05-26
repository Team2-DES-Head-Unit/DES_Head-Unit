#include <vsomeip/vsomeip.hpp>
#include <iostream>
#include <iomanip>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID 0x5678
#define SAMPLE_METHOD_ID 0x0421

std::shared_ptr<vsomeip::application> app;
std::mutex mutex;
std::condition_variable condition;
std::string gear_state = "P";  // 기본 기어 상태
std::string previous_gear_state = "";  // 이전 기어 상태

struct ControlData {
    float throttle;
    float steering;
    float distance;
    float speed;
    uint8_t gear_P;
    uint8_t gear_D;
    uint8_t gear_R;
    uint8_t gear_N;
    uint8_t indicator_l;
    uint8_t indicator_r;
};

// Python에서 기어 상태를 받는 함수
void receive_gear_state() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    // char buffer[1024] = {0};
    ControlData control_data;
    // 소켓 생성
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket creation error" << std::endl;
        return;
    }

    // 포트 번호 재사용 설정
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        std::cerr << "Setsockopt error" << std::endl;
        return;
    }

    // 주소 설정
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(65432);

    // 소켓에 주소 바인딩
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return;
    }

    // 연결 대기
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen error" << std::endl;
        return;
    }

    std::cout << "Waiting for connection from Python..." << std::endl;

    // 클라이언트 연결 수락
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        std::cerr << "Accept error" << std::endl;
        return;
    }

    while (true) {
        int valread = read(new_socket, &control_data, sizeof(ControlData));
        if (valread > 0) {
            if (control_data.gear_P == 1) gear_state = "P";
            else if (control_data.gear_D == 1) gear_state = "D";
            else if (control_data.gear_R == 1) gear_state = "R";
            else if (control_data.gear_N == 1) gear_state = "N";

            // 속도, 거리 출력
            std::cout << "Gear: " << gear_state
                      << " | Throttle: " << control_data.throttle
                      << " | Steering: " << control_data.steering
                      << " | Speed: " << control_data.speed << " cm/s"
                      << " | Distance: " << control_data.distance << " cm"
                      << std::endl;
        }
    }

    close(new_socket);
    close(server_fd);
}

// vsomeip 요청을 보내는 함수
void run() {
    std::unique_lock<std::mutex> its_lock(mutex);
    condition.wait(its_lock);

    while (true) {
        // 기어 상태가 변경되었는지 확인
        if (gear_state != previous_gear_state) {
            previous_gear_state = gear_state;  // 이전 기어 상태 업데이트

            std::shared_ptr<vsomeip::message> request = vsomeip::runtime::get()->create_request();
            request->set_service(SAMPLE_SERVICE_ID);
            request->set_instance(SAMPLE_INSTANCE_ID);
            request->set_method(SAMPLE_METHOD_ID);

            // 기어 상태를 페이로드로 포함
            std::shared_ptr<vsomeip::payload> its_payload = vsomeip::runtime::get()->create_payload();
            std::vector<vsomeip::byte_t> payload_data(gear_state.begin(), gear_state.end());
            its_payload->set_data(payload_data);
            request->set_payload(its_payload);

            app->send(request);
            std::cout << "CLIENT: Request sent with gear state: " << gear_state << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // 100ms 대기
    }
}

// vsomeip 응답 처리
void on_message(const std::shared_ptr<vsomeip::message> &_response) {
    std::cout << "CLIENT: Received response with payload: ";
    std::shared_ptr<vsomeip::payload> its_payload = _response->get_payload();
    for (uint32_t i = 0; i < its_payload->get_length(); ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') 
                  << static_cast<int>(its_payload->get_data()[i]) << " ";
    }
    std::cout << std::endl;
}

// 서비스 가용성 처리
void on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available) {
    std::cout << "CLIENT: Service [" << std::hex << _service << "." << _instance << "] is "
              << (_is_available ? "available." : "NOT available.") << std::endl;
    if (_is_available) {
        condition.notify_one();  // 요청 쓰레드에 신호 보내기
    }
}

int main() {
    app = vsomeip::runtime::get()->create_application("client-sample");
    app->init();

    app->register_availability_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, on_availability);
    app->request_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID, on_message);

    // 기어 상태를 받는 쓰레드 시작
    std::thread receiver(receive_gear_state);

    // vsomeip 요청을 보내는 쓰레드 시작
    std::thread sender(run);

    app->start();
}

