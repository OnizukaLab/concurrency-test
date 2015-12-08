#include "HashIncHLE.hpp"


HashIncHLE::HashIncHLE(int iters, int conc, int load, int len, int dens, int chunk, double ro)
: HashIncBase(iters, conc, load, len, dens, chunk, ro){}

void HashIncHLE::increment(int thread_num){
  #ifdef HTM
  int lockvar;
  while (__atomic_exchange_n (&lockvar, 1, __ATOMIC_ACQUIRE | __ATOMIC_HLE_ACQUIRE))
    _mm_pause ();

  auto sum = 0;
  for(int i = 0; i < _chunk; i++){
    auto num = _iters / _conc * thread_num + i;
    sum += _rw_list[num] ? ++_v[_index_list[num]] : _v[_index_list[num]];
  }
  intentional_load();
  __atomic_clear (&lockvar, __ATOMIC_RELEASE | __ATOMIC_HLE_RELEASE);
  #endif
}
