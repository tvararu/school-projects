#include <iostream>
using namespace std;

class A {
  int *v, dim;
public:
  A (int i) {
    dim = i;
    v = new int[i];
    for (int j = 1; j < dim; j++) {
      v[j] = j;
    }
  }
  
  int size() { return dim; }
  friend int& operator[] (A, int);
};

int& operator[] (A a, int i) {
  return *(a.v + a.size() - i);
}

int main (int argc, char const *argv[])
{
  A a(10);
  a[3] = 7;
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << ' ';
  }
  return 0;
}