#include "SimpleIncAtomic.hpp"


SimpleIncAtomic::SimpleIncAtomic(int thread_num, int loop_num): SimpleIncBase(thread_num, loop_num){}

function<void()> SimpleIncAtomic::_increment(){
  return [&](){
    _atomic_count++;
  };
}

long SimpleIncAtomic::get_count(){
  return _atomic_count.load();
}