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

class Inh : public Base {
public:
  int get_y() { return y; }
};

class Inh2 : public Inh {
public:
  int get_y() { return y; }
};

int main (int argc, char const *argv[])
{
  Inh a;
  cout << a.get_y() << endl;
  Inh2 b;
  cout << b.get_y() << endl;
  
  return 0;
}