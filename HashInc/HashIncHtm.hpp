#ifndef HASHINCHTM
#define HASHINCHTM
// #define HTM

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "HashIncBase.hpp"

using namespace std;


class HashIncHtm: public HashIncBase{
protected:
  function<void()> increment();
  
public:
  HashIncHtm(int thread_num, int loop_num, int len);
};

#endif