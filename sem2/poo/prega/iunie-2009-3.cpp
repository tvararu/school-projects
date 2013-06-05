// incorect; nu poti sa initializezi un obiect de tip clasa derivata cu un obiect de tip clasa parinte

#include <iostream>
using namespace std;

class A
{ protected: int x;
public: A(int i=-31) { x=i; }
virtual A operator+(A a) { return x+a.x; } };
class B: public A
{ public: B(int i=12) { x=i; }
B operator+(B b) { return x+b.x+1; }
void afisare(){ cout<<x; } };
int main()
{ A *p1=new B, *p2=new A;
B *p3=new A(p2->operator+(*p1)); p3->afisare();
return 0;
}