#include <iostream>
using namespace std;

class cls {
  int x;
public:
  cls (int i = -20) { x = i; }
  const int& f() { return x; }
};

int main (int argc, char const *argv[])
{
  cls a(14);
  int b = a.f()++;
  // a.f() intoarce const, si nu mai putem apela ++ pe el
  cout << b;
  return 0;
}