#ifndef HASHINCHLE
#define HASHINCHLE

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include <immintrin.h>
#include "HashIncBase.hpp"

using namespace std;


class HashIncHLE: public HashIncBase{
protected:
  void increment(int chunk_index);
  
public:
  HashIncHLE(int niters, int conc, int load, int len, int dens, int chunk, double ro);
};

#endif
