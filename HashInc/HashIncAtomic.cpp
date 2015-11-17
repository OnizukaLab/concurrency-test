#include "HashIncAtomic.hpp"


HashIncAtomic::HashIncAtomic(int thread_num, int loop_num, int len, int density, int chunk)
: HashIncBase(thread_num, loop_num, len, density, chunk), _atomic_v(len * density){}

function<void()> HashIncAtomic::increment(double prob){
  return [&](){
    for(int i = 0; i < _chunk; i++){
      auto index = rand_index();
      if(rand() % 10 < (int)(prob * 10))
        _atomic_v[index]++;
      //else
        //auto x = _atomic_v[index];
    }
  };
}

long HashIncAtomic::get_sum(){
  long sum = 0;
  for(int i = 0; i < _len; i++)
    sum += _atomic_v[i * _density].load();
  return sum;
}

void HashIncAtomic::print(){
  cout << "list: ";
  for(int i = 0; i < _len; i++)
    cout << _atomic_v[i * _density].load() << " ";
  cout << endl;
}
