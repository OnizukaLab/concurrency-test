#include "HashIncBase.hpp"


HashIncBase::HashIncBase(int thread_num, int loop_num, int len, int density, int chunk)
:_v(len * density, 0), _mt(_rd()), _distribution(0, len - 1){
  _thread_num = thread_num;
  _loop_num = loop_num;
  _len = len;
  _density = density;
  _chunk = chunk;
}

chrono::duration<double> HashIncBase::go(double prob = 1){
  return Util::measure_time([&](){
    for(int i = 0; i < _thread_num; i++)
      _threads.push_back(thread([=](){ 
        for(int j = 0; j < _loop_num / _thread_num; j++)
          increment(prob)();
      }));
    for(thread &th: _threads)
      th.join();
  });
}

long HashIncBase::rand_index(){
  return _distribution(_mt) * _density;
}

long HashIncBase::get_sum(){
  long sum = 0;
  for(int i = 0; i < _len; i++)
    sum += _v[i * _density];
  return sum;
}

void HashIncBase::print(){
  cout << "list: ";
  for(int i = 0; i < _len; i++)
    cout << _v[i * _density] << " ";
  cout << endl;
}
