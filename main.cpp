#define INC
#define HASH

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "SimpleInc/SimpleIncNoCtrl.hpp"
#include "SimpleInc/SimpleIncMutex.hpp"
#include "SimpleInc/SimpleIncHtm.hpp"
#include "SimpleInc/SimpleIncAtomic.hpp"
#include "HashInc/HashIncNoCtrl.hpp"
#include "HashInc/HashIncMutex.hpp"
#include "HashInc/HashIncHtm.hpp"
#include "HashInc/HashIncAtomic.hpp"

using namespace std;


int main(int argc, char **argv){
  auto loop = 1000000;
  auto num = 4;
  auto len = 20;
  
  cout << "loop: " << loop << endl;
  cout << "thread: " << num << endl;
  cout << "hash length: " << len << endl;
  
  #ifdef INC
  auto si_no_ctrl = new SimpleIncNoCtrl(num, loop);
  auto du_si_no_ctrl = si_no_ctrl->go();
  cout << "time (simple, no control): " << du_si_no_ctrl.count() << endl;
  cout << si_no_ctrl->get_count() << endl;
  
  auto si_mutex = new SimpleIncMutex(num, loop);
  auto du_si_mutex = si_mutex->go();
  cout << "time (simple, mutex): " << du_si_mutex.count() << endl;
  cout << si_mutex->get_count() << endl;
  
  auto si_htm = new SimpleIncHtm(num, loop);
  auto du_si_htm = si_htm->go();
  cout << "time (simple, htm): " << du_si_htm.count() << endl;
  cout << si_htm->get_count() << endl;
  
  auto si_atomic = new SimpleIncAtomic(num, loop);
  auto du_si_atomic = si_atomic->go();
  cout << "time (simple, atomic): " << du_si_atomic.count() << endl;
  cout << si_atomic->get_count() << endl;
  #endif
  
  #ifdef HASH  
  auto h_no_ctrl = new HashIncNoCtrl(num, loop, len);
  auto du_h_no_ctrl = h_no_ctrl->go();
  cout << "time (hash, no control): " << du_h_no_ctrl.count() << endl;
  cout << h_no_ctrl->get_sum() << "//";
  h_no_ctrl->print();
  
  auto h_mutex = new HashIncMutex(num, loop, len);
  auto du_h_mutex = h_mutex->go();
  cout << "time (hash, mutex): " << du_h_mutex.count() << endl;
  cout << h_mutex->get_sum() << "//";
  h_mutex->print();
  
  auto h_htm = new HashIncHtm(num, loop, len);
  auto du_h_htm = h_htm->go();
  cout << "time (hash, htm): " << du_h_htm.count() << endl;
  cout << h_htm->get_sum() << "//";
  h_htm->print();
  
  auto h_atomic = new HashIncAtomic(num, loop, len);
  auto du_h_atomic = h_atomic->go();
  cout << "time (hash, atomic): " << du_h_atomic.count() << endl;
  cout << h_atomic->get_sum() << "//";
  h_atomic->print();
  #endif
  
  return 0;
}
