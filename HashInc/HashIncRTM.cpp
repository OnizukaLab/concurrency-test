#include "HashIncRTM.hpp"


HashIncRTM::HashIncRTM(int iters, int conc, int load, int len, int dens, int chunk, double ro)
: HashIncBase(iters, conc, load, len, dens, chunk, ro){}

void HashIncRTM::increment(int chunk_index){
#ifdef HTM
  retry:
  int st = _xbegin();
  if (st == _XBEGIN_STARTED) {
    auto sum = 0;
    for(int i = 0; i < _chunk; i++){
      auto index = chunk_index + i;
      sum += _rw_list[index] ? ++_v[_index_list[index]] : _v[_index_list[index]];
    }
    intentional_load();
    _xend();
  } else {
    goto retry;
  }
#endif
}
