#include "HashIncAtomic.hpp"


HashIncAtomic::HashIncAtomic(int niters, int conc, int load, int len, int dens, int chunk, double ro)
: HashIncBase(niters, conc, load, len, dens, chunk, ro), _atomic_v(len * dens){}

void HashIncAtomic::increment(int chunk_index){
  auto sum = 0;
  for(int i = 0; i < _chunk; i++) {
    auto index = chunk_index + i;
    sum += _rw_list[index] ? ++_atomic_v[_index_list[index]] : _atomic_v[_index_list[index]].load();
  }
  intentional_load();
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
