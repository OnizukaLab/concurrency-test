#include "SimpleIncBase.hpp"


SimpleIncBase::SimpleIncBase(int thread_num, int loop_num){
  _thread_num = thread_num;
  _loop_num = loop_num;

  _count = 0;
}

chrono::duration<double> SimpleIncBase::go(){
  return Util::measure_time([&](){
    for(int i = 0; i < _thread_num; i++)
      _threads.push_back(thread([=](){ 
        for(int i = 0; i < _loop_num / _thread_num; i++)
          increment()();
      }));
    for(thread &th: _threads)
      th.join();
  });
}

long SimpleIncBase::get_count(){
  return _count;
}