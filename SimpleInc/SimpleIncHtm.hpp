#ifndef SIMPLEINCHTM_HPP
#define SIMPLEINCHTM_HPP

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
  function<void()> increment();

public:
  SimpleIncHtm(int thread_num, int loop_num);
};

#endif