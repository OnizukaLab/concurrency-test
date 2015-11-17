#include "HashIncHtmAtomic.hpp"


HashIncHtmAtomic::HashIncHtmAtomic(int thread_num, int loop_num, int len, int density, int chunk)
: HashIncBase(thread_num, loop_num, len, density, chunk){}

function<void()> HashIncHtmAtomic::increment(double prob){
  return [&](){
    #ifdef HTM
//    __transaction_atomic{
//      _v[rand()]++;
//    }
    #endif
  };
}
