#include <iostream>
using namespace std;

class Base {
  int x;
public:
  Base() { x = 3; }
  void ceva () { x = 14; }
  // void ceva () const { x = 14; }
  
  int getter () const { return x; }
};

int main (int argc, char const *argv[])
{
  Base a;
  a.ceva();
  cout << a.getter() << endl;
  return 0;
}