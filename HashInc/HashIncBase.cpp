#include "HashIncBase.hpp"


HashIncBase::HashIncBase(int niters, int conc, int load, double l_balance, int len, int dens, int chunk, double ro)
:_niters(niters), _conc(conc), _load(load), _l_balance(l_balance), _len(len), _dens(dens), _chunk(chunk), _ro(ro),
_v(len * dens, 0){
  for(int i = 0; i < _niters * _chunk; i++) {
    _index_list.push_back((rand() % _len) * _dens);
    _rw_list.push_back(rand() % 100 < (int)(_ro * 100));
  }
}

chrono::duration<double> HashIncBase::go(){
  return Util::measure_time([&](){
    for(int i = 0; i < _conc; i++)
      _threads.push_back(thread([=](){ 
        for(int j = 0; j < _niters / _conc; j++) {
          increment(_chunk * (i * _niters / _conc + j));
          intentional_load_outside();
        }
      }));
    for(thread &th: _threads)
      th.join();
  });
}

void HashIncBase::intentional_load_inside(){
  volatile auto dummy = 0;
  for(int i = 0; i < _load * _l_balance; i++){
    dummy++;
    dummy--;
  }
}

void HashIncBase::intentional_load_outside(){
  volatile auto dummy = 0;
  for(int i = 0; i < _load * (1.0 - _l_balance); i++){
    dummy++;
    dummy--;
  }
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
