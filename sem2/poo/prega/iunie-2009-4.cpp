// incorect, deoarece nu poti apela printr-o lista de initializare o variabila de tip static

#include <iostream>
using namespace std;
class A
{ int x;
static int y;
public: A(int i):x(i) {
  y++;
}
              int f() const; };
      int A::y;
int A::f() const { return y; }
int main()
{ const A a(21);
  cout<<a.f()<<endl;
  
  const A b(21);
  cout<<b.f()<<endl;
  
  const A c(21);
  cout<<c.f()<<endl;
  
  const A d(21);
  cout<<d.f()<<endl;
  
  const A e(21);
  cout<<e.f()<<endl;
  
  return 0; }