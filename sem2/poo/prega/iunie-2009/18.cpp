#include <iostream>
using namespace std;

template<class T>
T f (T x, T y) {
  return x + y;
}

int f (int x, int y) {
  return x - y;
}

int main (int argc, char const *argv[])
{
  int *a = new int(3), *b = new int(23);
  cout << f(a, b);
  
  return 0;
}