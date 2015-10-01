#include "SimpleIncMutex.hpp"


SimpleIncMutex::SimpleIncMutex(int thread_num, int loop_num): SimpleIncBase(thread_num, loop_num){}

function<void()> SimpleIncMutex::_increment(){
  return [&](){
    mtx.lock();
    _count++;
    mtx.unlock();
  };
}