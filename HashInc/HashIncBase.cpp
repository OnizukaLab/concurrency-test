#include "HashIncBase.hpp"


HashIncBase::HashIncBase(int thread_num, int loop_num, int len)
:_v(len * 8, 0), _mt(_rd()), _distribution(0, len - 1){
  _thread_num = thread_num;
  _loop_num = loop_num;
  _len = len;
}

chrono::duration<double> HashIncBase::go(){
  return Util::measure_time([&](){
    for(int i = 0; i < _thread_num; i++)
      _threads.push_back(thread([=](){ 
        for(int j = 0; j < _loop_num / _thread_num; j++)
          increment()();
      }));
    for(thread &th: _threads)
      th.join();
  });
}

long HashIncBase::rand(){
  return _distribution(_mt) * 8;
}

long HashIncBase::get_sum(){
  long sum = 0;
  for(int i = 0; i < _v.size(); i += 8)
    sum += _v[i];
  return sum;
}

void HashIncBase::print(){
  cout << "list: ";
  for(int i = 0; i < _v.size(); i += 8)
    cout << _v[i] << " ";
  cout << endl;
}