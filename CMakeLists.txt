cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "-std=c++11 -pthread -fgnu-tm -mhle -mrtm -Wall -g -O1 -shared-libgcc")

project(concurrency-test CXX)
add_executable(concurrency-test
  Main.cpp
  Util.hpp
  Util.cpp
  Define.hpp
  HashInc/HashIncBase.hpp
  HashInc/HashIncBase.cpp
  HashInc/HashIncNoCtrl.hpp
  HashInc/HashIncNoCtrl.cpp
  HashInc/HashIncMutex.hpp
  HashInc/HashIncMutex.cpp
  HashInc/HashIncHtmAtomic.hpp
  HashInc/HashIncHtmAtomic.cpp
  HashInc/HashIncHtmRelaxed.hpp
  HashInc/HashIncHtmRelaxed.cpp
  HashInc/HashIncHLE.hpp
  HashInc/HashIncHLE.cpp
  HashInc/HashIncRTM.hpp
  HashInc/HashIncRTM.cpp
  HashInc/HashIncAtomic.hpp
  HashInc/HashIncAtomic.cpp
)
