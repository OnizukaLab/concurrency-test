#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>

using namespace std;


static mutex mtx;
static long shared_cnt_no_ctrl = 0;
static long shared_cnt_mutex = 0;
static atomic<long> shared_cnt_atomic(0);
static long shared_cnt_htm = 0;


chrono::duration<double> measure_time(function<void()> f){
  const auto startTime = chrono::system_clock::now();
  
  f();
  
  const auto endTime = chrono::system_clock::now();
  return endTime - startTime;
}

static function<void()> inc_no_ctrl = [](){
  shared_cnt_no_ctrl++;
};

static function<void()> inc_mutex = [](){
  mtx.lock();
  shared_cnt_mutex++;
  mtx.unlock();
};

static function<void()> inc_atomic = [](){
  shared_cnt_atomic++;
};

static function<void()> inc_htm = [](){
  __transaction_atomic{
    shared_cnt_htm++;
  }
};

chrono::duration<double> go(function<void()> f, int loop, vector<thread>& ths, int num){
  return measure_time([&](){
    for(int i = 0; i < num; i++)
      ths.push_back(thread([=](){ 
        for(int i = 0; i < loop; i++)
          f();
      }));
    for(thread &th: ths)
      th.join();
  });
}

int main(int argc, char **argv){
  auto loop = 1000000;
  auto num = 4;
  
  vector<thread> threads_no_ctrl;
  auto d_no_ctrl = go(inc_no_ctrl, loop, threads_no_ctrl, num);
  cout << "time no control: " << d_no_ctrl.count() << endl;
  
  vector<thread> threads_mutex;
  auto d_mutex = go(inc_mutex, loop, threads_mutex, num);
  cout << "time mutex: " << d_mutex.count() << endl;
  
  vector<thread> threads_atomic;
  auto d_atomic = go(inc_atomic, loop, threads_atomic, num);
  cout << "time atomic: " << d_atomic.count() << endl;
  
  vector<thread> threads_htm;
  auto d_htm = go(inc_mutex, loop, threads_htm, num);
  cout << "time htm: " << d_htm.count() << endl;
  
  return 0;
}
