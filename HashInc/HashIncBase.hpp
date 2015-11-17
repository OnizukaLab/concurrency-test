#ifndef HASHINCBASE
#define HASHINCBASE

#include <cstdlib>
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
private:
  random_device _rd;
  mt19937 _mt;
  uniform_int_distribution<long> _distribution;

protected:
  int _len;
  int _thread_num;
  int _loop_num;
  int _density;
  int _chunk;
  vector<thread> _threads;
  vector<long> _v;
  long rand_index();
  virtual function<void()> increment(double prob) = 0;
  
public:
  HashIncBase(int thread_num, int loop_num, int len, int density, int chunk);
  
  chrono::duration<double> go(double prob);
  virtual long get_sum();
  virtual void print();
};

#endif
