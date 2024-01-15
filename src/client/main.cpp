#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <zmq.hpp>

#include "message_data.pb.h"

int main(int argc, char *argv[]) {
    unsigned short uuid = 0;
    message_data::heartbeat hb;

    if (argc == 1) {
        std::string arg = argv[1];
        try {
            std::size_t pos;
            uuid = std::stoi(arg, &pos);
            if (pos < arg.size()) {
                std::cerr << "trailing characters after number: " << arg << '\n';
            }
        } catch (std::invalid_argument const &ex) {
            std::cerr << "invalid number: " << arg << '\n';
        } catch (std::out_of_range const &ex) {
            std::cerr << "number out of range: " << arg << '\n';
        }
    }
    std::cout << "uuid= " << uuid << std::endl;

    // initialize the zmq context with a single IO thread
    zmq::context_t context{1};

    // construct a REQ (request) socket and connect to interface
    zmq::socket_t socket{context, zmq::socket_type::req};
    socket.connect("tcp://localhost:5555");

    // set up some static data to send
    const std::string data{"Hello "};

    for (auto request_num = 0; request_num < 10; ++request_num)
    {
        // send the request message
        std::string data_to_send = data + std::to_string(request_num);
        std::cout << "Sending \"" << data_to_send << "\"" << std::endl;
        auto res = socket.send(zmq::buffer(data_to_send), zmq::send_flags::none);

        std::cout << "wait " << res.value() << std::endl;
        // wait for reply from server
        zmq::message_t reply{};
        std::optional<size_t> ret = socket.recv(reply, zmq::recv_flags::none);

        std::cout << "Received \"" << reply.to_string() << "\"" << std::endl;
//        std::cout << " (" << request_num << ")";
//        std::cout << std::endl;
    }

    return 0;
}