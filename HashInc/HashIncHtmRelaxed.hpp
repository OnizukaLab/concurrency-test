#ifndef HASHINCHTMRELAXED
#define HASHINCHTMRELAXED

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "HashIncBase.hpp"

using namespace std;


class HashIncHtmRelaxed: public HashIncBase{
protected:
  function<void()> increment();
  
public:
  HashIncHtmRelaxed(int thread_num, int loop_num, int len);
};

#endif