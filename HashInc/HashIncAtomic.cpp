#include "HashIncAtomic.hpp"


HashIncAtomic::HashIncAtomic(int iters, int conc, int load, int len, int dens, int chunk, double ro)
: HashIncBase(iters, conc, load, len, dens, chunk, ro), _atomic_v(len * dens){}

void HashIncAtomic::increment(){
  const auto rnd = rand();
  const auto index = rand_index();

  auto sum = 0;
  for(int i = 0; i < _chunk; i++)
    sum += (rnd % 100 < (int)(_ro * 100)) ? ++_atomic_v[index] : _atomic_v[index].load();
  for(int i = 0; i < _load; i++){
    sum++;
    sum--;
  }
}

long HashIncAtomic::get_sum(){
  long sum = 0;
  for(int i = 0; i < _len; i++)
    sum += _atomic_v[i * _dens].load();
  return sum;
}

void HashIncAtomic::print(){
  cout << "list: ";
  for(int i = 0; i < _len; i++)
    cout << _atomic_v[i * _dens].load() << " ";
  cout << endl;
}
