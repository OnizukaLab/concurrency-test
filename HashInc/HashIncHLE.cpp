#include "HashIncHLE.hpp"


HashIncHLE::HashIncHLE(int niters, int conc, int load, int len, int dens, int chunk, double ro)
: HashIncBase(niters, conc, load, len, dens, chunk, ro){}

void HashIncHLE::increment(int chunk_index){
#ifdef HTM
  int lockvar;
  while (__atomic_exchange_n (&lockvar, 1, __ATOMIC_ACQUIRE | __ATOMIC_HLE_ACQUIRE))
    _mm_pause ();

  auto sum = 0;
  for(int i = 0; i < _chunk; i++){
    auto index = chunk_index + i;
    sum += _rw_list[index] ? ++_v[_index_list[index]] : _v[_index_list[index]];
  }
  intentional_load();
  __atomic_clear (&lockvar, __ATOMIC_RELEASE | __ATOMIC_HLE_RELEASE);
#endif
}
