#include <iostream>
#include <chrono>
#include <future>
#include "HashInc/HashIncNoCtrl.hpp"
#include "HashInc/HashIncMutex.hpp"
#include "HashInc/HashIncHtmAtomic.hpp"
#include "HashInc/HashIncHtmRelaxed.hpp"
#include "HashInc/HashIncHLE.hpp"
#include "HashInc/HashIncRTM.hpp"
#include "HashInc/HashIncAtomic.hpp"

using namespace std;

int main(int argc, char **argv){  
  auto type = stoi(argv[1]);
  auto niters = stoi(argv[2]);
  auto conc = stoi(argv[3]);
  auto load = stoi(argv[4]);
  auto len = stoi(argv[5]);
  auto dens = stoi(argv[6]);
  auto chunk = stoi(argv[7]);
  auto w_rate = stod(argv[8]);

  switch(type){
    case 0:{
      auto inc0 = new HashIncHLE(niters, conc, load, len, dens, chunk, w_rate);
      auto res0 = inc0->go();
      cout << res0.count() << endl;
      break;
    }
    case 1:{
      auto inc1 = new HashIncRTM(niters, conc, load, len, dens, chunk, w_rate);
      auto res1 = inc1->go();
      cout << res1.count() << endl;
      break;
    }
    case 2:{
      auto inc2 = new HashIncHtmAtomic(niters, conc, load, len, dens, chunk, w_rate);
      auto res2 = inc2->go();
      cout << res2.count() << endl;
      break;
    }
    case 3:{
      auto inc3 = new HashIncHtmRelaxed(niters, conc, load, len, dens, chunk, w_rate);
      auto res3 = inc3->go();
      cout << res3.count() << endl;
      break;
    }
    case 4:{
      auto inc4 = new HashIncMutex(niters, conc, load, len, dens, chunk, w_rate);
      auto res4 = inc4->go();
      cout << res4.count() << endl;
      break;
    }
    case 5:{
      auto inc5 = new HashIncAtomic(niters, conc, load, len, dens, chunk, w_rate);
      auto res5 = inc5->go();
      cout << res5.count() << endl;
      break;
    }
    case 6:{
      auto inc6 = new HashIncNoCtrl(niters, conc, load, len, dens, chunk, w_rate);
      auto res6 = inc6->go();
      cout << res6.count() << endl;
      break;
    }
    default:
      cout << "no match" << endl;
      break;
  }
  
  return 0;
}
