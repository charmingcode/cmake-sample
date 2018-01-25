cmake_minimum_required(VERSION 2.8)
project(C11-SAMPLE)
# For any C code, use the same flags.
#set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(lamda_thread lamda_thread.cc)
