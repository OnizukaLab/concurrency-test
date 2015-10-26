#include "HashIncHtmRelaxed.hpp"


HashIncHtmRelaxed::HashIncHtmRelaxed(int thread_num, int loop_num, int len)
: HashIncBase(thread_num, loop_num, len){}

function<void()> HashIncHtmRelaxed::increment(){
  return [&](){
    #ifdef HTM
    __transaction_relaxed{
      _v[rand()]++;
    }
    #endif
  };
}