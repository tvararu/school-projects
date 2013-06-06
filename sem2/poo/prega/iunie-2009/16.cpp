#include <iostream>
using namespace std;

int f (int y) {
  if (y < 0) throw y;
  // se executa pentru -35 si trece direct la catch
  return y / 2;
}

int main (int argc, char const *argv[])
{
  int x;
  
  try {
    cout << "Da-mi un numar par: -35\n";
    // cin >> x;
    x = -35;
    if (x % 2) x = f(x);
    else throw x;
    cout << "Numarul " << x << " e bun!" << endl;
  }
  
  catch (int i) {
    cout << "Numarul " << i << " nu e bun!" << endl;
    // afiseaza -35 cu succes
  }
  
  return 0;
}