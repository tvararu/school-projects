#include <iostream>
using namespace std;

int main (int argc, char const *argv[])
{
  try {
    // throw 1;
    // throw (float)1.2;
    throw 1.2;
    cout << "Nu se afiseaza." << endl;
  }
  
  catch (int) {
    cerr << "Caught int exception" << endl;
  }
  catch (float) {
    cerr << "Caught float exception" << endl;
  }
  catch (double d) {
    cerr << "Caught double = " << d << " exception" << endl;
  }
  return 0;
}