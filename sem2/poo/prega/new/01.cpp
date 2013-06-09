#include <iostream> 
#include <typeinfo> 
using namespace std;
class A {
  int x;
public:
  A (int i = 7) { x = i; }
  int get_x() { return x; }
  operator int () { return x; }
}; 

class B : public A
{
public:
  B (int i = -12) : A(i) {}
// B operator + (B g) {
//  cout << "g: " << g.get_x();
//  return get_x() + g.get_x();}
};
  
int main()
{
  B a;
  int b = -21; 
  b = b + a;
  cout << b << endl;
  return 0;
}
