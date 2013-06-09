#include <iostream>
using namespace std;

class A {
protected:
  int x;
public:
  A (int i) : x(i) {}
  int get_x() { return x; }
};

class B : public A {
public:
  B (int i) : A(i) {}
  B operator+ (const B& b) { return x + b.x; }
};

int main (int argc, char const *argv[])
{
  B a(23), b(-15);
  cout << a + b;
  return 0;
}