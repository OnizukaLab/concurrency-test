#include "HashIncHLE.hpp"


HashIncHLE::HashIncHLE(int iters, int conc, int load, int len, int dens, int chunk, double ro)
: HashIncBase(iters, conc, load, len, dens, chunk, ro){}

void HashIncHLE::increment(){
  #ifdef HTM
  const auto rnd = rand();
  const auto index = rand_index();

  int lockvar;
  while (__atomic_exchange_n (&lockvar, 1, __ATOMIC_ACQUIRE | __ATOMIC_HLE_ACQUIRE))
    _mm_pause ();

  auto sum = 0;
  for(int i = 0; i < _chunk; i++)
    sum += (rnd % 100 < (int)(_ro * 100)) ? ++_v[index] : _v[index];
  for(int i = 0; i < _load; i++){
    sum++;
    sum--;
  }

  __atomic_clear (&lockvar, __ATOMIC_RELEASE | __ATOMIC_HLE_RELEASE);
  #endif
}
