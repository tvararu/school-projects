#include <iostream>
using namespace std;

class A {
  int x;
  static int y;
public:
  A (int i, int j) : x(i), y(j) {} // y(j) e gresit
  int f() const;
};

int A::y;
int A::f() const { return y; }

int main() {
  const A a(21);
  cout << a.f() << endl;
  
  return 0;
}