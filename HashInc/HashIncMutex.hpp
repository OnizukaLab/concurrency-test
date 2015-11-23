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
  void increment();
  
public:
  HashIncMutex(int iters, int conc, int load, int len, int dens, int chunk, double ro);
};

#endif
