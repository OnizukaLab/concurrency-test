#include "HashIncRTM.hpp"


HashIncRTM::HashIncRTM(int iters, int conc, int load, int len, int dens, int chunk, double ro)
: HashIncBase(iters, conc, load, len, dens, chunk, ro){}

void HashIncRTM::increment(){
  #ifdef HTM
  retry:
  const auto rnd = rand();
  const auto index = rand_index();

  int st = _xbegin();
  if (st == _XBEGIN_STARTED) {
  auto sum = 0;
  for(int i = 0; i < _chunk; i++)
    sum += (rnd % 100 < (int)(_ro * 100)) ? ++_v[index] : _v[index];
  for(int i = 0; i < _load; i++){
    sum++;
    sum--;
  }
    _xend();
  } else {
    goto retry;
  }
  #endif
}