#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <thread>

using namespace std;


static pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
static long shared_cnt_no_ctrl = 0;
static long shared_cnt_mutex = 0;
static long shared_cnt_htm = 0;


static chrono::duration<double> measure_time(function<void()> f){
  const auto startTime = chrono::system_clock::now();
  
  f();
  
  const auto endTime = chrono::system_clock::now();
  return endTime - startTime;
}

static function<void()> inc_no_ctrl = [](){
    shared_cnt_no_ctrl++;
  };

static function<void()> inc_mutex = [](){
    pthread_mutex_lock(&m);
    shared_cnt_mutex++;
    pthread_mutex_unlock(&m);
  };

static function<void()> inc_htm = [](){
    __transaction_atomic{
      shared_cnt_htm++;
    }
  };

static function<void(int, function<void()>)> loop = [](int max, function<void()> f){
    for(int i = 0; i < max; i++)
      f();
  };

static void* wrapper_no_ctrl(void* args){
  loop(1000000, inc_no_ctrl);
  return 0;
}

static void* wrapper_mutex(void* args){
  loop(1000000, inc_mutex);
  return 0;
}

static void* wrapper_htm(void* args){
  loop(100000, inc_htm);
  return 0;
}

int main(int argc, char **argv){
  auto n = 32;
  auto *threads = new pthread_t[n];
  
  auto t_no_ctrl = measure_time([=](){
    for(int i = 0; i < n; ++i)
      pthread_create(&threads[i], NULL, wrapper_no_ctrl, NULL);
    for(int i = 0; i < n; ++i)
      pthread_join(threads[i], 0);
  });
  cout << "time: " << t_no_ctrl.count() << endl;

  auto t_mutex = measure_time([=](){
    for(int i = 0; i < n; ++i)
      pthread_create(&threads[i], NULL, wrapper_mutex, NULL);
    for(int i = 0; i < n; ++i)
      pthread_join(threads[i], 0);
  });  
  cout << "time: " << t_mutex.count() << endl;
  
  auto t_htm = measure_time([=](){
    for(int i = 0; i < n; ++i)
      pthread_create(&threads[i], NULL, wrapper_htm, NULL);
    for(int i = 0; i < n; ++i)
      pthread_join(threads[i], 0);
  });  
  cout << "time: " << t_htm.count() << endl;

  return 0;
}
