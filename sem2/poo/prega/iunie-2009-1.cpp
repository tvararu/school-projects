// corect

#include <iostream>
using namespace std;

class A
{ int x;
public: A(int i=0) { x=i; }
A operator+(const A& a) { return x+a.x; }
template <class T> friend ostream& operator<<(ostream&,T); };
template <class T>
ostream& operator<<(ostream& o, T t) { o<<t.x; return o; } int main()
{ A a1(33), a2(-21);
        cout<<a1+a2;
return 0; }