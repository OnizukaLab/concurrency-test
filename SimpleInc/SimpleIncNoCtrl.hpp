#ifndef SIMPLEINCNOCTRL_HPP
#define SIMPLEINCNOCTRL_HPP

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "SimpleIncBase.hpp"

using namespace std;


class SimpleIncNoCtrl: public SimpleIncBase{
protected:
  function<void()> increment();

public:
  SimpleIncNoCtrl(int thread_num, int loop_num);
};

#endif