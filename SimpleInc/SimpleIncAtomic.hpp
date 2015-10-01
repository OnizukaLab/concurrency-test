#ifndef SIMPLEINCATOMIC_HPP
#define SIMPLEINCATOMIC_HPP

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "SimpleIncBase.hpp"

using namespace std;


class SimpleIncAtomic: public SimpleIncBase{
private:
  atomic<long> _atomic_count;

protected:
  function<void()> increment();

public:
  SimpleIncAtomic(int thread_num, int loop_num);
  
  long get_count();
};

#endif