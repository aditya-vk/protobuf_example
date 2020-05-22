project(proto_example)
cmake_minimum_required(VERSION 2.8.3)
set(CMAKE_CXX_FLAGS "-g -Werror -std=c++14")

add_subdirectory(proto)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable(main main.cpp)
target_link_libraries(main proto ${PROTOBUF_LIBRARY})
