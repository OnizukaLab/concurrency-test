#include "HashIncNoCtrl.hpp"


HashIncNoCtrl::HashIncNoCtrl(int iters, int conc, int load, int len, int dens, int chunk, double ro)
: HashIncBase(iters, conc, load, len, dens, chunk, ro){}

void HashIncNoCtrl::increment(int thread_num){
  auto sum = 0;
  for(int i = 0; i < _chunk; i++){
    auto num = _iters / _conc * thread_num + i;
    sum += _rw_list[num] ? ++_v[_index_list[num]] : _v[_index_list[num]];
  }
  intentional_load();
}
