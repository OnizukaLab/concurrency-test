#ifndef SIMPLEINCHTM_HPP
#define SIMPLEINCHTM_HPP
#define HTM

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "SimpleIncBase.hpp"

using namespace std;


class SimpleIncHtm: public SimpleIncBase{
protected:
  function<void()> _increment();

public:
  SimpleIncHtm(int thread_num, int loop_num);
};

#endif