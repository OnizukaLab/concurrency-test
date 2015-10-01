#ifndef HASHINCBASE
#define HASHINCBASE

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include <random>
#include <algorithm>
#include "../Util.hpp"
#include "../Define.hpp"

using namespace std;


class HashIncBase{
protected:
  int _len;
  int _thread_num;
  int _loop_num;
  vector<thread> _threads;
  vector<long> _v;
  random_device _rd;
  mt19937 _mt;
  uniform_int_distribution<long> _distribution;
  virtual function<void()> increment() = 0;
  
public:
  HashIncBase(int thread_num, int loop_num, int len);
  
  chrono::duration<double> go();
  virtual long get_sum();
  virtual void print();
};

#endif