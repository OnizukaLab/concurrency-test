#include "HashIncHtmAtomic.hpp"


HashIncHtmAtomic::HashIncHtmAtomic(int thread_num, int loop_num, int len)
: HashIncBase(thread_num, loop_num, len){}

function<void()> HashIncHtmAtomic::increment(){
  return [&](){
    #ifdef HTM
    __transaction_atomic{
      _v[rand()]++;
    }
    #endif
  };
}