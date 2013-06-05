#include <iostream>
using namespace std;

class A {
  int x;
public:
  A (int i = 0) : x(i) {}
  int get_x () { return x; }
  int& set_x (int i) { x = i; }
  // also functie non-void care nu intoarce nimic. warning.
};

// declarare incorecta, trebuie cu :: (operatorul de rezolutie)
A operator= (A a1, A a2) {
  a1.set_x(a2.get_x());
  return a2;
}

int main()
{ 
  A a(212), b;
  cout << (b=a).get_x();
  return 0;
}