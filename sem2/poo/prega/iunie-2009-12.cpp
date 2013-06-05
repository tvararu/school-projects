// incorect; la apelarea functiei f(a) se va incerca copierea obiectului de tip const A intr-un obiect local metodei f, pentru ca functia f primeste parametru prin valoare. deoarece nu avem constructor de copiere care sa primeasca ca parametru o referinta spre un obiect de tip constant (i.e.: A(const A& a) ), aceasta operatie va esua.

#include <iostream>
using namespace std;

class A
{
  int x, *y;
public:
  A(int i) { x=i; y=new int[x]; }
  A(A& a) { x=a.x; y=new int[x]; }
  // A(const A& a) { x=a.x; y=new int[x]; }
  // merge cu linia asta ^
  int get_x() const { return x; }
};

int f (A a) { return a.get_x(); }

int main()
{
  const A a(5);
  cout<<(a.get_x()==f(a));
  return 0;
}