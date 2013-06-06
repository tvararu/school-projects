#include <iostream>
using namespace std;

class A {
public:
  void nothing() {}
};

class B : virtual public A {
};

class C : virtual public A {
};

class D : public B, public C {
};

int main (int argc, char const *argv[])
{
  D x;
  x.nothing();
  
  return 0;
}