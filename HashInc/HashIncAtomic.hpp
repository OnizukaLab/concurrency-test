#ifndef HASHINCATOMIC
#define HASHINCATOMIC

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "HashIncBase.hpp"

using namespace std;


class HashIncAtomic: public HashIncBase{
private:
  vector<atomic<long>> _atomic_v;

protected:
  void increment();
  
public:
  HashIncAtomic(int iters, int conc, int load, int len, int dens, int chunk, double ro);
  
  long get_sum();
  void print();
};

#endif
