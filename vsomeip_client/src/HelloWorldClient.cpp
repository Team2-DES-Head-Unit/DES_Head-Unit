#include <vsomeip/vsomeip.hpp>
#include <iostream>
#include <iomanip>
#include <thread>
#include <condition_variable>
#include <chrono>

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID 0x5678
#define SAMPLE_METHOD_ID 0x0421

std::shared_ptr<vsomeip::application> app;
std::mutex mutex;
std::condition_variable condition;

void run() {
    std::unique_lock<std::mutex> its_lock(mutex);
    condition.wait(its_lock);

    while (true) {
        std::shared_ptr<vsomeip::message> request = vsomeip::runtime::get()->create_request();
        request->set_service(SAMPLE_SERVICE_ID);
        request->set_instance(SAMPLE_INSTANCE_ID);
        request->set_method(SAMPLE_METHOD_ID);

        // Create a request with no payload (just a simple request)
        app->send(request);
        std::cout << "CLIENT: Request sent!" << std::endl;

        // Wait for 100ms before sending the next request
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void on_message(const std::shared_ptr<vsomeip::message> &_response) {
    std::cout << "CLIENT: Received response with payload: ";
    std::shared_ptr<vsomeip::payload> its_payload = _response->get_payload();
    for (uint32_t i = 0; i < its_payload->get_length(); ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') 
                  << static_cast<int>(its_payload->get_data()[i]) << " ";
    }
    std::cout << std::endl;
}

void on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available) {
    std::cout << "CLIENT: Service [" << std::hex << _service << "." << _instance << "] is "
              << (_is_available ? "available." : "NOT available.") << std::endl;
    if (_is_available) {
        condition.notify_one(); // Notify the sender thread to send the request
    }
}

int main() {
    app = vsomeip::runtime::get()->create_application("client-sample");
    app->init();

    app->register_availability_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, on_availability);
    app->request_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);
    app->register_message_handler(vsomeip::ANY_SERVICE, vsomeip::ANY_INSTANCE, SAMPLE_METHOD_ID, on_message);

    std::thread sender(run);
    app->start();
}

