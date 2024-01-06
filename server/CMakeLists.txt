project(zmq_server)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
        ${PROJECT_NAME}
        cppzmq
)
message("< ${CMAKE_PROJECT_NAME} / ${PROJECT_NAME}")