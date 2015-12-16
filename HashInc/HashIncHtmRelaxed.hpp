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
  void increment(int chunk_index);
  
public:
  HashIncHtmRelaxed(int niters, int conc, int load, int len, int dens, int chunk, double ro);
};

#endif
