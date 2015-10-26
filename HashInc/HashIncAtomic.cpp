#include "HashIncAtomic.hpp"


HashIncAtomic::HashIncAtomic(int thread_num, int loop_num, int len)
: HashIncBase(thread_num, loop_num, len), _atomic_v(len * 8){}

function<void()> HashIncAtomic::increment(){
  return [&](){
    _atomic_v[_distribution(_mt) * 8]++;
  };
}

long HashIncAtomic::get_sum(){
  long sum = 0;
  for(int i = 0; i < _atomic_v.size(); i += 8)
    sum += _atomic_v[i].load();
  return sum;
}

void HashIncAtomic::print(){
  cout << "list: ";
  for(int i = 0; i < _atomic_v.size(); i += 8)
    cout << _atomic_v[i].load() << " ";
  cout << endl;
}