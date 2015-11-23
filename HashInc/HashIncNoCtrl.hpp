#ifndef HASHINCNOCTRL
#define HASHINCNOCTRL

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "HashIncBase.hpp"

using namespace std;


class HashIncNoCtrl: public HashIncBase{
protected:
  void increment();
  
public:
  HashIncNoCtrl(int iters, int conc, int load, int len, int dens, int chunk, double ro);
};

#endif
