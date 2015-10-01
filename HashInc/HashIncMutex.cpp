#include "HashIncMutex.hpp"


HashIncMutex::HashIncMutex(int thread_num, int loop_num, int len)
: HashIncBase(thread_num, loop_num, len){}

function<void()> HashIncMutex::increment(){
  return [&](){
    _mtx.lock();
    _v[_distribution(_mt)]++;
    _mtx.unlock();
  };
}