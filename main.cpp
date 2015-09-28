#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  auto x = 10;
  
  __transaction_atomic {
    x++;
  }
  
  cout << x << "\n";
  return 0;
}