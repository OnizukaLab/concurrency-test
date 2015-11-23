#ifndef HASHINCRTM
#define HASHINCRTM

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include <immintrin.h>
#include "HashIncBase.hpp"

using namespace std;


class HashIncRTM: public HashIncBase{
protected:
  void increment();
  
public:
  HashIncRTM(int iters, int conc, int load, int len, int dens, int chunk, double ro);
};

#endif
