#include <iostream>
using namespace std;

class A;

class B {
  int x;
public:
  B (int i = 107) { x = i; }
  operator A();
};

B::operator A() { return x; }
// ar merge daca linia asta e mutata mai jos

// ar merge si daca declararea astalalta s-ar face mai sus
class A {
  int x;
public:
  A (int i = 6) { x = i; }
  int get_x () { return x; }
}; 

int main()
{
  B b;
  A a = b;
  cout << a.get_x();
  return 0;
}