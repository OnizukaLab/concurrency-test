#define INC
// #define HASH

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "SimpleInc/SimpleIncBase.hpp"
#include "SimpleInc/SimpleIncNoCtrl.hpp"
#include "SimpleInc/SimpleIncMutex.hpp"
#include "SimpleInc/SimpleIncHtm.hpp"
#include "SimpleInc/SimpleIncAtomic.hpp"

using namespace std;


int main(int argc, char **argv){
  auto loop = 1000000;
  auto num = 4;
  
  #ifdef INC
  auto si_no_ctrl = new SimpleIncNoCtrl(num, loop);
  auto du_no_ctrl = si_no_ctrl->go();
  cout << "time no control: " << du_no_ctrl.count() << endl;
  cout << si_no_ctrl->get_count() << endl;
  
  auto si_mutex = new SimpleIncMutex(num, loop);
  auto du_mutex = si_mutex->go();
  cout << "time mutex: " << du_mutex.count() << endl;
  cout << si_mutex->get_count() << endl;
  
  auto si_htm = new SimpleIncHtm(num, loop);
  auto du_htm = si_htm->go();
  cout << "time htm: " << du_htm.count() << endl;
  cout << si_htm->get_count() << endl;
  
  auto si_atomic = new SimpleIncAtomic(num, loop);
  auto du_atomic = si_atomic->go();
  cout << "time atomic: " << du_atomic.count() << endl;
  cout << si_atomic->get_count() << endl;
  #endif
  
  #ifdef HASH
  
  #endif
  
  return 0;
}
