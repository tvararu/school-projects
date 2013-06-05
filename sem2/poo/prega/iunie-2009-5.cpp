#include <iostream>
using namespace std;

class Ionel {
};

class Costel {
};

int main (int argc, char const *argv[])
{
  Ionel ionut;
  cout << typeid(ionut).name() << endl;
  
  Costel costica;
  cout << typeid(costica).name() << endl;
  
  return 0;
}