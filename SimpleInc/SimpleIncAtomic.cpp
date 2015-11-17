#include "SimpleIncAtomic.hpp"


SimpleIncAtomic::SimpleIncAtomic(int thread_num, int loop_num)
: SimpleIncBase(thread_num, loop_num), _atomic_count(0){}

function<void()> SimpleIncAtomic::increment(){
  return [&](){
    _atomic_count++;
  };
}

long SimpleIncAtomic::get_count(){
  return _atomic_count.load();
}