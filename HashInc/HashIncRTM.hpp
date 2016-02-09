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
  void increment(int chunk_index);
  
public:
  HashIncRTM(int niters, int conc, int load, double l_balance, int len, int dens, int chunk, double ro);
};

#endif
