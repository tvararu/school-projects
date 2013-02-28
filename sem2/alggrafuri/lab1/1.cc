#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

void show_mat (vector< vector<int> > &mat, const int &n, ostream &out) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      out << mat[i][j] << ' ';
    }
    out << '\n';
  }
}

void show_grade (vector<int> &grad, const int &n, ostream &out) {
  for (int i = 0; i < n; i++) {
    out << grad[i] << ' ';
  }
  out << '\n';
}

int main (int argc, char const *argv[])
{
	srand(time(0));
  
  int n = 6;
  
  vector< vector<int> > matAdi(n, vector<int>(n));
  
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      matAdi[i][j] = matAdi[j][i] = rand() % 2;
    }
  }
  
  show_mat(matAdi, n, cout);
  
  vector<int> grad(n);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      grad[i] += matAdi[i][j];
    }
  }
  
  ofstream out ("input.in");
  out << n << '\n';
  show_grade(grad, n, out);
  out.close();
  
  return 0;
}