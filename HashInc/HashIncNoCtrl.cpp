#include "HashIncNoCtrl.hpp"


HashIncNoCtrl::HashIncNoCtrl(int thread_num, int loop_num, int len)
: HashIncBase(thread_num, loop_num, len){}

function<void()> HashIncNoCtrl::increment(){
  return [&](){
    _v[_distribution(_mt)]++;
  };
}