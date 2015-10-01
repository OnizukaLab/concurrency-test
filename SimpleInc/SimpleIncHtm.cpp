#include "SimpleIncHtm.hpp"


SimpleIncHtm::SimpleIncHtm(int thread_num, int loop_num)
: SimpleIncBase(thread_num, loop_num){}

function<void()> SimpleIncHtm::increment(){
  return [&](){
    #ifdef HTM
    __transaction_atomic{
      _count++;
    }
    #endif
  };
}