#ifndef HASHINCNOCTRL
#define HASHINCNOCTRL

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "HashIncBase.hpp"

using namespace std;


class HashIncNoCtrl: public HashIncBase{
protected:
  function<void()> increment(double prob);
  
public:
  HashIncNoCtrl(int thread_num, int loop_num, int len, int density, int chunk);
};

#endif
