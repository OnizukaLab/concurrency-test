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
  void increment(int chunk_index);
  
public:
  HashIncHtmAtomic(int niters, int conc, int load, double l_balance, int len, int dens, int chunk, double ro);
};

#endif
