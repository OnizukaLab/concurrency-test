#ifndef SIMPLEINCBASE_HPP
#define SIMPLEINCBASE_HPP

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "../Util.hpp"

using namespace std;


class SimpleIncBase{
protected:
  int _count;
  int _thread_num;
  int _loop_num;
  vector<thread> threads;
  virtual function<void()> _increment() = 0;

public:
  SimpleIncBase(int thread_num, int loop_num);
  
  chrono::duration<double> go();
  virtual long get_count();
};

#endif