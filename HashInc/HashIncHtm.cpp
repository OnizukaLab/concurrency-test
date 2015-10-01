#include "HashIncHtm.hpp"


HashIncHtm::HashIncHtm(int thread_num, int loop_num, int len)
: HashIncBase(thread_num, loop_num, len){}

function<void()> HashIncHtm::increment(){
  return [&](){
    #ifdef HTM
    __transaction_atomic{
      _v[_distribution(_mt)]++;
    }
    #endif
  };
}