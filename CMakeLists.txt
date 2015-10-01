cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "-std=c++11 -pthread -fgnu-tm -Wall")

project(htm-sample CXX)
add_executable(htm-sample
  Main.cpp
  Util.cpp
  Util.hpp
  SimpleInc/SimpleIncBase.cpp
  SimpleInc/SimpleIncBase.hpp
  SimpleInc/SimpleIncNoCtrl.cpp
  SimpleInc/SimpleIncNoCtrl.hpp
  SimpleInc/SimpleIncMutex.cpp
  SimpleInc/SimpleIncMutex.hpp
  SimpleInc/SimpleIncHtm.cpp
  SimpleInc/SimpleIncHtm.hpp
  SimpleInc/SimpleIncAtomic.cpp
  SimpleInc/SimpleIncAtomic.hpp
)