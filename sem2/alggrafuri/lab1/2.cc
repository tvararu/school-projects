#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <utility>
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

//mp = make pair
pair<int, int> mp (const int &a, const int &b) {
  pair<int, int> x;
  x.first = a;
  x.second = b;
  
  return x;
}

void show_set (set< pair<int, int> > &setul) {
  for (typeof(setul.rbegin()) it = setul.rbegin(); it != setul.rend(); it++) {
    cout << it->first << ' ' << it->second << '\n';
  }
  cout << '\n';
}

int main (int argc, char const *argv[])
{
  ifstream in ("input.in");
  int n; in >> n;
  
  set< pair<int, int> > setul;
  
  for (int i = 0; i < n; i++) {
    int x;
    in >> x;
    setul.insert(mp(x, i));
  }
  
  show_set(setul);
  
  vector< vector<int> > matAdi(n, vector<int>(n));
  vector< pair<int, int> > removed;
  
  while (!setul.empty()) {
    pair<int, int> top = *(setul.rbegin());
    setul.erase(*setul.rbegin());
    // show_set(setul);
    while (top.first--) {
      pair<int, int> pop = *(setul.rbegin());
      setul.erase(*setul.rbegin());
      pop.first--;
      matAdi[top.second][pop.second] = matAdi[pop.second][top.second] = 1;
      removed.push_back(pop);
    }
    for (unsigned i = 0; i < removed.size(); i++) {
      setul.insert(removed[i]);
    }
    removed.clear();
    show_set(setul);
    // break;
  }
  
  show_mat(matAdi, n, cout);
  
  return 0;
}