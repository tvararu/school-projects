#include <iostream>
using namespace std;

class B {
public:
  int x;
  B (int i = 16) { x = i; }
  B f (B ob) { return x + ob.x; }
  // daca f era virtuala, se comporta diferit
};

class D : public B {
public:
  D (int i = 25) { x = i; }
  B f (B ob) { return x + ob.x + 1; }
  void afisare () { cout << x; }
};

int main (int argc, char const *argv[])
{
  // pentru claritate, am rescris declaratiile in mod echivalent
  B *p1 = new D;
  B *p2 = new B;
  B *p3 = new B(p1->f(*p2));
  cout << p3->x;
  
  return 0;
}