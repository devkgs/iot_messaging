cmake_minimum_required(VERSION 3.11)
set(CMAKE_BUILD_TYPE Debug)

project(iot_messaging)

set(CMAKE_CXX_STANDARD 17)

find_package(cppzmq)

add_subdirectory(client)
add_subdirectory(server)

#add_executable(
#        ${CMAKE_PROJECT_NAME}
#        main.cpp
#)
#
#target_link_libraries(
#        ${CMAKE_PROJECT_NAME}
#        cppzmq
#)