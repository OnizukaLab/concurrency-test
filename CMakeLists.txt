cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "-std=c++11 -fgnu-tm -Wall")

project(htm-sample CXX)
add_executable(htm-sample main.cpp)