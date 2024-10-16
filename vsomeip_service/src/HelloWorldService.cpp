#include <vsomeip/vsomeip.hpp>
#include <iostream>
#include <iomanip>

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID 0x5678
#define SAMPLE_METHOD_ID 0x0421

std::shared_ptr<vsomeip::application> app;

void on_message(const std::shared_ptr<vsomeip::message> &_request) {
    std::cout << "SERVER: Received request!" << std::endl;

    // Create response
    std::shared_ptr<vsomeip::message> response = vsomeip::runtime::get()->create_response(_request);
    std::shared_ptr<vsomeip::payload> its_payload = vsomeip::runtime::get()->create_payload();

    // Set a simple response payload
    std::vector<vsomeip::byte_t> response_data{0x55, 0xAA};
    its_payload->set_data(response_data);
    response->set_payload(its_payload);

    std::cout << "SERVER: Sending response with payload: ";
    for (auto byte : response_data) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;

    app->send(response);
}

int main() {
    app = vsomeip::runtime::get()->create_application("service-sample");
    app->init();

    // Register a message handler for incoming requests
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID, on_message);

    // Offer the service
    app->offer_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);

    std::cout << "SERVER: Service started and waiting for requests..." << std::endl;

    app->start();
}

