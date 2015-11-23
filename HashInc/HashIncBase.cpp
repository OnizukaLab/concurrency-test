#include "HashIncBase.hpp"


HashIncBase::HashIncBase(int iters, int conc, int load, int len, int dens, int chunk, double ro)
:_iters(iters), _conc(conc), _load(load), _len(len), _dens(dens), _chunk(chunk), _ro(ro),
_v(len * dens, 0), _mt(_rd()), _distribution(0, len - 1){ }

chrono::duration<double> HashIncBase::go(){
  return Util::measure_time([&](){
    for(int i = 0; i < _conc; i++)
      _threads.push_back(thread([=](){ 
        for(int j = 0; j < _iters / _conc; j++)
          increment();
      }));
    for(thread &th: _threads)
      th.join();
  });
}

long HashIncBase::rand_index(){
  return _distribution(_mt) * _dens;
}

long HashIncBase::get_sum(){
  long sum = 0;
  for(int i = 0; i < _len; i++)
    sum += _v[i * _dens];
  return sum;
}

void HashIncBase::print(){
  cout << "list: ";
  for(int i = 0; i < _len; i++)
    cout << _v[i * _dens] << " ";
  cout << endl;
}
