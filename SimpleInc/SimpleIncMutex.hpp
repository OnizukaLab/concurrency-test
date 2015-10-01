#ifndef SIMPLEINCMUTEX_HPP
#define SIMPLEINCMUTEX_HPP

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "SimpleIncBase.hpp"

using namespace std;


class SimpleIncMutex: public SimpleIncBase{
private:
  mutex mtx;

protected:
  function<void()> _increment();

public:
  SimpleIncMutex(int thread_num, int loop_num);
};

#endif