cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "-std=c++11 -pthread -fgnu-tm -Wall")

project(htm-sample CXX)
add_executable(htm-sample
  Main.cpp
  Util.hpp
  Util.cpp
  SimpleInc/SimpleIncBase.hpp
  SimpleInc/SimpleIncBase.cpp
  SimpleInc/SimpleIncNoCtrl.hpp
  SimpleInc/SimpleIncNoCtrl.cpp
  SimpleInc/SimpleIncMutex.hpp
  SimpleInc/SimpleIncMutex.cpp
  SimpleInc/SimpleIncHtm.hpp
  SimpleInc/SimpleIncHtm.cpp
  SimpleInc/SimpleIncAtomic.hpp
  SimpleInc/SimpleIncAtomic.cpp
  HashInc/HashIncBase.hpp
  HashInc/HashIncBase.cpp
  HashInc/HashIncNoCtrl.hpp
  HashInc/HashIncNoCtrl.cpp
  HashInc/HashIncMutex.hpp
  HashInc/HashIncMutex.cpp
  HashInc/HashIncHtm.hpp
  HashInc/HashIncHtm.cpp
  HashInc/HashIncAtomic.hpp
  HashInc/HashIncAtomic.cpp
)