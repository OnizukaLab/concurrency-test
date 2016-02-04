#include "HashIncHLE.hpp"


HashIncHLE::HashIncHLE(int niters, int conc, int load, double l_balance, int len, int dens, int chunk, double ro)
: HashIncBase(niters, conc, load, l_balance, len, dens, chunk, ro){}

void HashIncHLE::increment(int chunk_index) {
#ifdef HTM
  while (__atomic_exchange_n(&_lock_var, 1, __ATOMIC_ACQUIRE | __ATOMIC_HLE_ACQUIRE))
    _mm_pause();

  auto sum = 0;
  for (int i = 0; i < _chunk; i++) {
    auto index = chunk_index + i;
    sum += _rw_list[index] ? ++_v[_index_list[index]] : _v[_index_list[index]];
  }
  intentional_load_inside();
  __atomic_clear(&_lock_var, __ATOMIC_RELEASE | __ATOMIC_HLE_RELEASE);
#endif
}
