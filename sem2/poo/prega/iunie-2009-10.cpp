// incorect; *p1 = p1->minus() o sa schimbe tipul de obiect retinut in pointerul p1 la un obiect de tip A, pentru ca functia minus() intoarce A. prin urmare, metoda de afisare() va fi cautata in cadrul obiectului A, care nu are aceasta metoda.

#include <iostream>
using namespace std;

class A
{
public:
  int x;
  A(int i=0) { x=i; }
  virtual A minus() { return(1-x); }
};

class B: public A
{ public:
  B(int i=0) { x=i; }
  void afisare() { cout<<x; }
};

int main()
{
  A *p1=new B(18);
  *p1=p1->minus();
  p1->afisare();
  return 0;
}