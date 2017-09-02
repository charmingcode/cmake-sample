cmake_minimum_required(VERSION 2.8)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${PROJECT_SOURCE_DIR}/usr/local/share/hello/cmake/")

find_package(testHello REQUIRED)

message(WARNING "include_dir = ${HELLO_INCLUDE_DIR}")
include_directories(${HELLO_INCLUDE_DIR})

add_executable(sample2 test.cc)
target_link_libraries(sample2 hello)
