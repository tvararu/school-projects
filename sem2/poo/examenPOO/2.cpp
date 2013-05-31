#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

class Punct {
  double x, y, z;
public:
  Punct () : x(0.0), y(0.0), z(0.0) {}
  Punct (Punct& p) {
    x = p.x;
    y = p.y;
    z = p.z;
  }
  Punct (double xValue, double yValue, double zValue) {
    x = xValue;
    y = yValue;
    z = zValue;
  }
  
  Punct* setX (double value) { x = value; return this; }
  Punct* setY (double value) { y = value; return this; }
  Punct* setZ (double value) { z = value; return this; }
  
  double getX () { return x; }
  double getY () { return y; }
  double getZ () { return z; }
  
  friend ostream& operator<< (ostream& out, Punct &p) {
    out << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return out;
  }
  
  Punct operator+ (Punct &p) {
    Punct result = *this;
    result.x = (x + p.x) / 2;
    result.y = (y + p.y) / 2;
    result.z = (z + p.z) / 2;
    return result;
  }
};

double segment (Punct &p, Punct &q) {
  return sqrt(  pow((p.getX() - q.getX()), 2) +
                pow((p.getY() - q.getY()), 2) +
                pow((p.getZ() - q.getZ()), 2) );
}

class Triplet {
  Punct a, b, c;
public:
  Triplet () : a(), b(), c() {}
  Triplet (Punct p, Punct q, Punct r) {
    a = p;
    b = q;
    c = r;
  }
  
  friend ostream& operator<< (ostream& out, Triplet &t) {
    out << t.a.getX() << " " << t.a.getY() << " " << t.a.getZ() << endl;
    out << t.b.getX() << " " << t.b.getY() << " " << t.b.getZ() << endl;
    out << t.c.getX() << " " << t.c.getY() << " " << t.c.getZ() << endl;
    return out;
  }
  
  friend istream& operator>> (istream& in, Triplet &t) {
    double x, y, z;
    in >> x >> y >> z;
    t.a.setX(x)->setY(y)->setZ(z);
    in >> x >> y >> z;
    t.b.setX(x)->setY(y)->setZ(z);
    in >> x >> y >> z;
    t.c.setX(x)->setY(y)->setZ(z);
    return in;
  }
  
  bool isTriangle () {
    return (segment(a, b) + segment(b, c)) > segment(a, c);
  }
  
  virtual double aria () {
    double A = segment(b, c), B = segment(a, c), C = segment(a, b);
    double p = (A + B + C) / 2;
    return sqrt( p * (p - A) * (p - B) * (p - C) );
  }
  
  friend class Triunghi;
};

class Triunghi : public Triplet {
public:
  Triunghi () : Triplet () {}
  Triunghi (Punct p, Punct q, Punct r) : Triplet (p, q, r) {}
  
  virtual double aria () {
    // presupunem ca A este ipotenuza, B si C sunt catetele
    double B = segment(a, c), C = segment(a, b);
    return (B * C) / 2;
  }
};

int main (int argc, char const *argv[])
{
  // punctul a)
  Punct p(3.1, 4.2, 5.3);
  cout << p << endl;
  
  Punct q(p);
  cout << q << endl;
  q.setX(1)->setY(2)->setZ(3);
  cout << q << endl;
  
  Punct r;
  r = p + q;
  cout << p << ' ' << q << ' ' << r << endl;
  cout << endl;

  // punctul b)
  r.setX(14)->setY(13.2)->setZ(2.1);
  Triplet t(p, q, r);
  
  cout << t;
  ofstream out ("2.in");
  out << t;
  out.close();
  
  ifstream in ("2.in");
  Triplet input;
  in >> input;
  cout << input;
  in.close();
  
  cout << (t.isTriangle() ? "Este triunghi." : "Nu este triunghi.") << endl;
  cout << "Are aria de: " << t.aria() << endl;
  cout << endl;
  
  // punctul c)
  Punct a(0, 0, 0), b(1, 0, 0), c(0, 1, 0);
  Triunghi triangle(a, b, c);
  cout << triangle;
  cout << triangle.aria() << endl;
  
  return 0;
}