// incorect; daca intr-o clasa derivata nu declaram niciun constructor, aceasta va mosteni constructorii clasei de baza. dar, daca in clasa mostenitoare, declaram un constructor care accepta parametru, această clasa nu mai mosteneste constructorii impliciti. prin urmare, declaratia B b1; va esua cu "no matching constructor"

#include <iostream>
using namespace std;

class A
{
protected:
  int x;
public:
  A(int i=14) { x=i; }
};

class B: A
{
public:
  B(B& b) { x=b.x; }
  void afisare() { cout<<x; }
};

int main()
{
  B b1, b2(b1);
  b2.afisare();
  return 0;
}