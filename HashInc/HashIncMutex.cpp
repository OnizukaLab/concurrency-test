#include "HashIncMutex.hpp"


HashIncMutex::HashIncMutex(int iters, int conc, int load, int len, int dens, int chunk, double ro)
: HashIncBase(iters, conc, load, len, dens, chunk, ro){}

void HashIncMutex::increment(){
  const auto rnd = rand();
  const auto index = rand_index();

  auto sum = 0;
  _mtx.lock();
  for(int i = 0; i < _chunk; i++)
    sum += (rnd % 100 < (int)(_ro * 100)) ? ++_v[index] : _v[index];
  for(int i = 0; i < _load; i++){
    sum++;
    sum--;
  }
  _mtx.unlock();
}
