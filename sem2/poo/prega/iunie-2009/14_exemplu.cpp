#include <iostream>
using namespace std;

class Base {
  int x;
public:
  Base() { x = 3; }
  void ceva () { x = 14; }
  // void ceva () const { x = 14; }
  // a se observa cu si fara const
  
  int getter () const { return x; }
  // getterii sunt un exemplu de functii care merg de regula facuti const fara probleme la compilare
};

int main (int argc, char const *argv[])
{
  // a se observa cu si fara const
  const Base a;
  a.ceva();
  cout << a.getter() << endl;
  return 0;
}