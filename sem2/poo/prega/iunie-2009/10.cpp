#include <iostream>
using namespace std;

class A {
public:
  int x;
  A (int i = 0) { x = i; }
  virtual A minus() { return (1 - x); }
};

class B: public A {
public:
  B (int i = 0) { x = i; }
  void afisare() { cout << x; }
};

int main()
{
  A *p1 = new B(18);
  *p1 = p1->minus(); // rvalue intoarce un A
  p1->afisare(); // iar un A nu are metoda de afisare
  return 0;
}