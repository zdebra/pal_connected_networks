cmake_minimum_required(VERSION 3.6)
project(pal_connected_networks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(pal_connected_networks ${SOURCE_FILES})