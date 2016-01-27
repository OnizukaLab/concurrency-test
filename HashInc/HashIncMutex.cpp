#include "HashIncMutex.hpp"


HashIncMutex::HashIncMutex(int niters, int conc, int load, double l_balance, int len, int dens, int chunk, double ro)
: HashIncBase(niters, conc, load, l_balance, len, dens, chunk, ro){}

void HashIncMutex::increment(int chunk_index){
  _mtx.lock();
  auto sum = 0;
  for(int i = 0; i < _chunk; i++) {
    auto index = chunk_index + i;
    sum += _rw_list[index] ? ++_v[_index_list[index]] : _v[_index_list[index]];
  }
  intentional_load_inside();
  _mtx.unlock();
}
