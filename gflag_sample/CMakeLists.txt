cmake_minimum_required(VERSION 2.8)
project(GFALG_SAMPLE)
if(APPLE)
    set(CMAKE_MACOSX_RPATH 1)
endif()

include_directories("/home/kudu/usr/thirdparty/installed/uninstrumented/include")
link_directories("/home/kudu/usr/thirdparty/installed/uninstrumented/lib")

add_executable(sample test.cc)

target_link_libraries(sample gflags)