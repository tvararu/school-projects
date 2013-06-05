#include <iostream>
using namespace std;

class Base {
public:
  Base () {}
};

class Derived : virtual public Base {
public:
  Derived (int i) {}
};

int main (int argc, char const *argv[])
{
  Derived a;
  
  return 0;
}