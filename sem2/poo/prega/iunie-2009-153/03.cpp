#include <iostream>

class A {
  int x;
public:
  A (int i = 25) { x = i; }
  friend int& f(const A&);
};

int& f (const A& c) { return c.x; }

int main (int argc, char const *argv[])
{
  A a(25);
  cout << f(a);
  return 0;
}