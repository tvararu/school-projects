#include <iostream>
using namespace std;

class cls {
  int x;
public:
  cls (int i) { x = i; }
  int set_x (int i) { int y = x; x = i; return y; }
  int get_x () { return x; }
};

int main (int argc, char const *argv[])
{
  cls *p = new cls[10];
  // prima problema, nu are constructor fara parametrii
  int i = 0;
  for (; i < 10; i++) {
    p[i].set_x(i);
  }
  for (i = 0; i < 10; i++) {
    cout << p[i].get_x(i);
    // a doua problema, apelarea metodei get_x cu parametru
  }
  
  return 0;
}