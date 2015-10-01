#ifndef HASHINCATOMIC
#define HASHINCATOMIC

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "HashIncBase.hpp"

using namespace std;


class HashIncAtomic: public HashIncBase{
private:
  vector<atomic<long>> _atomic_v;

protected:
  function<void()> increment();
  
public:
  HashIncAtomic(int thread_num, int loop_num, int len);
  
  long get_sum();
  void print();
};

#endif