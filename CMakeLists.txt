cmake_minimum_required(VERSION 3.11)
project(first)

set(CMAKE_CXX_STANDARD 17)

find_package(cppzmq)

add_executable(
        demo
        main.cpp
)

target_link_libraries(
        demo
        cppzmq
)