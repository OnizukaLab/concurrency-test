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
#include "HashInc/HashIncHtmAtomic.hpp"
#include "HashInc/HashIncHtmRelaxed.hpp"
#include "HashInc/HashIncAtomic.hpp"

using namespace std;

int main(int argc, char **argv){
  auto loop = 1000000;
  auto num = 4;
  
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
  auto kind = stoi(argv[1]);
  auto thread_num = stoi(argv[2]);
  auto loop_num = stoi(argv[3]);
  auto len = stoi(argv[4]);
  auto density = stoi(argv[5]);
  auto chunk = stoi(argv[6]);
  auto prob = stoi(argv[7]);

  switch(kind){
    case 0:{
      auto inc0 = new HashIncNoCtrl(thread_num, loop_num, len, density, chunk);
      auto res0 = inc0->go(prob);
      cout << res0.count() << endl;
      break;
    }
    case 1:{
      auto inc1 = new HashIncMutex(thread_num, loop_num, len, density, chunk);
      auto res1 = inc1->go(prob);
      cout << res1.count() << endl;
      break;
    }
    case 2:{
      auto inc2 = new HashIncHtmAtomic(thread_num, loop_num, len, density, chunk);
      auto res2 = inc2->go(prob);
      cout << res2.count() << endl;
      break;
    }
    case 3:{
      auto inc3 = new HashIncHtmRelaxed(thread_num, loop_num, len, density, chunk);
      auto res3 = inc3->go(prob);
      cout << res3.count() << endl;
      break;
    }
    case 4:{
      auto inc4 = new HashIncAtomic(thread_num, loop_num, len, density, chunk);
      auto res4 = inc4->go(prob);
      cout << res4.count() << endl;
      break;
    }
    default:
      break;
  }
  #endif
  
  return 0;
}
