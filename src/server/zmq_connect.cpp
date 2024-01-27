#include "zmq_connect.h"
#include <zmq.hpp>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>

void start(void){
    using namespace std::chrono_literals;
    std::cout << "=== ZMQ server ===" << std::endl;
    // initialize the zmq context with a single IO thread
    zmq::context_t context{1};

    // construct a REP (reply) socket and bind to interface
    zmq::socket_t socket{context, zmq::socket_type::rep};
    socket.bind("tcp://*:5555");

    // prepare some static data for responses
    const std::string data{"Answer to:"};

    for (;;)
    {
        zmq::message_t request;

        // receive a request from client
        std::optional<size_t> ret = socket.recv(request, zmq::recv_flags::none);
        std::cout << "SERVER<Received \"" << request.to_string() << "\"" << std::endl;
        //std::cout << "ret= " << ret.has_value() << std::endl;

        // simulate work
        std::this_thread::sleep_for(1s);

        // send the reply to the client
        socket.send(zmq::buffer(data+request.to_string()), zmq::send_flags::none);
    }
}