#include <iostream>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

int main (int argc, char const *argv[])
{
  ifstream in ("4.in");
  queue<char> coada;
  
  while (in) {
    string command;
    in >> command;
    
    if (command == "push") {
      char x; in >> x;
      coada.push(x);
    } else if (command == "pop") {
      if (!coada.empty()) {
        coada.pop();
      }
    } else if (command == "top") {
      cout << coada.front() << '\n';
    } else if (command == "show") {
      while (!coada.empty()) {
        cout << coada.front();
        coada.pop();
      }
      cout << '\n';
    }
  }
  
  in.close();
  
  return 0;
}