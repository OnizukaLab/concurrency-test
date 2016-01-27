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
  void increment(int chunk_index);
  
public:
  HashIncAtomic(int niters, int conc, int load, double l_balance, int len, int dens, int chunk, double ro);
  
  long get_sum();
  void print();
};

#endif
