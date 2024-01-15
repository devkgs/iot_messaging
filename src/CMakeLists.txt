cmake_minimum_required(VERSION 3.11)
set(CMAKE_BUILD_TYPE Debug)

project(iot_messaging)

set(CMAKE_CXX_STANDARD 17)

find_package(cppzmq REQUIRED)

add_subdirectory(proto)
add_subdirectory(client)
add_subdirectory(server)
