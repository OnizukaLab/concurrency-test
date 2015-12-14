#ifndef HASHINCBASE
#define HASHINCBASE

#include <cstdlib>
#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include <random>
#include <algorithm>
#include "../Util.hpp"
#include "../Define.hpp"

using namespace std;


class HashIncBase{
protected:
  const int _iters;
  const int _conc;
  const int _load;
  const int _len;
  const int _dens;
  const int _chunk;
  const double _ro;
  vector<thread> _threads;
  vector<long> _v;
  vector<long> _index_list;
  vector<bool> _rw_list;
  virtual void increment(int thread_num) = 0;
  
public:
  HashIncBase(int iters, int conc, int load, int len, int dens, int chunk, double ro);
  
  chrono::duration<double> go();
  __attribute__((transaction_safe)) void intentional_load();
  virtual long get_sum();
  virtual void print();
};

#endif
