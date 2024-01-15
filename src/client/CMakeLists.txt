project(zmq_client)

add_executable(${PROJECT_NAME} main.cpp)

set_source_files_properties(${PROTO_SRC} ${PROTO_HEADER} PROPERTIES
        GENERATED TRUE)
include_directories(${CMAKE_BINARY_DIR}/msg)

target_link_libraries(
        ${PROJECT_NAME}
        cppzmq
        proto_lib
)

message("< ${CMAKE_PROJECT_NAME} / ${PROJECT_NAME}")