#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// mi-am zis ca ar fi ca aplicatie practica draguta un parser simplu de html asa ca am scris si niste clase mici ajutatoare pentru asta
#include "html.cpp"
#include "tree.cpp"

int main (int argc, char const *argv[])
{
  Tree copac(Tag("h1"));
  
  copac += Tree(Tag("p"));
  copac += Tree(Tag("p"));
  copac += Tree(Tag("p"));
  copac += copac;
  copac += Tree(Tag("p"));
  
  // cout << Tag("span").attr("src", "google.com").open_tag();
  
  cout << copac << endl;
  
  return 0;
}