# add_library : add a library target to be build from the listed source files.
# target_include_directories : specifies include directories to use when compililng a given target.
# target_link_libraries:

find_package(Protobuf REQUIRED)

set(PROTO_FILES
        message_data.proto
)

add_library(proto_lib STATIC ${PROTO_FILES} )
target_include_directories(proto_lib INTERFACE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(proto_lib
        PUBLIC
        protobuf::libprotobuf
)

protobuf_generate(TARGET proto_lib LANGUAGE cpp)

#
#file(GLOB ProtoFiles "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")
#PROTOBUF_GENERATE_CPP(ProtoSources ProtoHeaders ${ProtoFiles})
#add_library(proto_lib STATIC ${ProtoSources} ${ProtoHeaders})
#target_include_directories(proto_lib PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
#
#target_link_libraries(proto_lib ${Boost_LIBRARIES} ${PROTOBUF_LIBRARY})
