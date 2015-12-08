#include "HashIncRTM.hpp"


HashIncRTM::HashIncRTM(int iters, int conc, int load, int len, int dens, int chunk, double ro)
: HashIncBase(iters, conc, load, len, dens, chunk, ro){}

void HashIncRTM::increment(int thread_num){
  #ifdef HTM
  retry:
  int st = _xbegin();
  if (st == _XBEGIN_STARTED) {
    auto sum = 0;
    for(int i = 0; i < _chunk; i++){
      auto num = _iters / _conc * thread_num + i;
      sum += _rw_list[num] ? ++_v[_index_list[num]] : _v[_index_list[num]];
    }
    intentional_load();
    _xend();
  } else {
    goto retry;
  }
  #endif
}
