#ifndef HASHINCHTMATOMIC
#define HASHINCHTMATOMIC

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "HashIncBase.hpp"

using namespace std;


class HashIncHtmAtomic: public HashIncBase{
protected:
  void increment();
  
public:
  HashIncHtmAtomic(int iters, int conc, int load, int len, int dens, int chunk, double ro);
};

#endif
