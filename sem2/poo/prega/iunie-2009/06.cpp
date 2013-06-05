#include <iostream>
using namespace std;

class A {
public:
  int *v, dim;
  A (int i) {
    dim = i;
    v = new int[dim];
    for (int j = 0; j < dim; j++) {
      v[j] = j;
    }
  }
  
  A (A& a) {
    dim = a.dim;
    v = new int[dim];
    for (int j = 0; j < dim; j++) {
      v[j] = a.v[j];
    }
  }
  
  ~A() { delete[] v; }
  
  int size() { return dim; }
  int& operator[] (int i) { return v[i]; }
  A operator+ (A a1);
};

A A::operator+ (A a1) {
  A a2(0);
  a2.dim = dim;
  v = new int[a2.dim];
  // weird, v este din this si nu din a2
  for (int j = 0; j < a2.dim; j++) {
    a2.v[j] = v[j] + a1.v[j];
  }
  return a2;
}

ostream& operator<< (ostream& o, A a) {
  for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  // weird, cout in loc de o
  return o;
}

int main (int argc, char const *argv[])
{
  A a(10), b(10), c(10);
  c = a + b;
  cout << c;
  return 0;
}
