#ifndef HASHINCMUTEX
#define HASHINCMUTEX

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "HashIncBase.hpp"

using namespace std;


class HashIncMutex: public HashIncBase{
private:
  mutex _mtx;

protected:
  function<void()> increment();
  
public:
  HashIncMutex(int thread_num, int loop_num, int len);
};

#endif