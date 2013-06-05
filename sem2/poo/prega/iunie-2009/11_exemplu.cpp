#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
  virtual string render () { return "???"; }
};

class Circle : public Shape {
public:
  virtual string render () { return "circle"; }
};

class Square : public Shape {
public:
  virtual string render () { return "square"; }
};

int main (int argc, char const *argv[])
{
  Shape *shapev[100];
  shapev[0] = new Circle();
  shapev[1] = new Square();
  shapev[2] = new Shape();
  
  // a se observa outputul cu si fara keywordul "virtual" la functia de render
  cout << shapev[0]->render() << endl;
  cout << shapev[1]->render() << endl;
  cout << shapev[2]->render() << endl;
  
  return 0;
}