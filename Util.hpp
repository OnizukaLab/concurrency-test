#ifndef UTILL_HPP
#define UTILL_HPP

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>

using namespace std;


class Util{
public:
  static chrono::duration<double> measure_time(function<void()> f);
};

#endif