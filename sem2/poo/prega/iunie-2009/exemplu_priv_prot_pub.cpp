#include <iostream>
using namespace std;

class Base {
private:
  int x;
protected:
  int y;
public:
  int z;
  Base() { x = 1; y = 2; z = 3; }
};

class Derived : public Base {
public:
  int get_y() { return y; }
};

class Derived2 : public Derived {
public:
  int get_y() { return y; }
};

int main (int argc, char const *argv[])
{
  Derived a;
  cout << a.get_y() << endl;
  Derived2 b;
  cout << b.get_y() << endl;
  
  return 0;
}