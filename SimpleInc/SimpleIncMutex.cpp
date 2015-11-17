#include "SimpleIncMutex.hpp"


SimpleIncMutex::SimpleIncMutex(int thread_num, int loop_num)
: SimpleIncBase(thread_num, loop_num){}

function<void()> SimpleIncMutex::increment(){
  return [&](){
    _mtx.lock();
    _count++;
    _mtx.unlock();
  };
}