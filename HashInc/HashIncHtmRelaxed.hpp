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
  void increment();
  
public:
  HashIncHtmRelaxed(int iters, int conc, int load, int len, int dens, int chunk, double ro);
};

#endif
