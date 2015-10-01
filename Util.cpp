#include "Util.hpp"


chrono::duration<double> Util::measure_time(function<void()> f){
  const auto startTime = chrono::system_clock::now();
  
  f();
  
  const auto endTime = chrono::system_clock::now();
  return endTime - startTime;
}