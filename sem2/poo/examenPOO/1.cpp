#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main (int argc, char const *argv[])
{
  ifstream in ("1.in");
  int N; in >> N;
  cout << N << endl;;
  
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    in >> v[i];
  }
  
  vector<bool> deal(N);
  for (int i = 0, deal = 1; i < N; i++, deal = 1) {
    // deal = 0, not a hill
    // deal = 1, a short hill out of 1 or 2 characters
    // deal = 2, a regular hill
    int ultima = -1;
    cout << v[i];
    while (v[i]) {
      int cifra = v[i] % 10;
      if (ultima != -1) {
        if (cifra >= ultima && deal == 2) {
          // if encountered a new hill but already found a hill
          deal = 0;
          break;
        } else if (cifra < ultima) {
          // found a hill
          deal = 2;
        }
      }
      
      v[i] /= 10;
      ultima = cifra;
    }
    cout << ((deal) ? " este deal." : " nu este deal.") << endl;
  }
  
  return 0;
}