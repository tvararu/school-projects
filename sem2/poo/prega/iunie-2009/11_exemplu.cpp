#include <iostream>
using namespace std;

class Form {
public:
  virtual string render () { return "???"; }
};

class Circle : public Form {
public:
  virtual string render () { return "circle"; }
};

class Square : public Form {
public:
  virtual string render () { return "square"; }
};

int main (int argc, char const *argv[])
{
  Form *formv[100];
  formv[0] = new Circle();
  formv[1] = new Square();
  formv[2] = new Form();
  
  // a se observa outputul cu si fara keywordul "virtual" la functia de render
  cout << formv[0]->render() << endl;
  cout << formv[1]->render() << endl;
  cout << formv[2]->render() << endl;
  
  return 0;
}