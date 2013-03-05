#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

void read_set (set<int> &v, const int &n, istream &in) {
  for (int i = 0; i < n; i++) {
    int x; in >> x;
    v.insert(x);
  }
}

void show_set (set<int> &v, ostream &out) {
  for (typeof(v.begin()) it = v.begin(); it != v.end(); it++) {
    out << *it << ' ';
  }
  out << '\n';
}

void read_vector (vector<int> &v, const int &n, istream &in) {
  for (int i = 0; i < n; i++) {
    in >> v[i];
  }
}

void show_vector (vector<int> &v, ostream &out) {
  for (typeof(v.begin()) it = v.begin(); it != v.end(); it++) {
    out << *it << ' ';
  }
  out << '\n';
}

void read_matadi (vector< vector<int> > &v, const int &m, istream &in) {
  for (int i = 0; i < m; i++) {
    int x, y, z; in >> x >> y >> z;
    v[x][y] = z;
  }
}

void show_matadi (vector< vector<int> > &v, ostream &out) {
  for (unsigned i = 0; i < v.size(); i++) {
    for (unsigned j = 0; j < v.size(); j++) {
      out << v[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main (int argc, char const *argv[])
{
  ifstream in ("input2.in");
  
  int n;
  
  in >> n;
  set<int> state;
  read_set(state, n, in);
  cout << "State set: ";
  show_set(state, cout);
  
  // 
  // in >> n;
  // set<int> alphabet;
  // read_set(alphabet, n, in);
  // cout << "Input alphabet: ";
  // show_set(alphabet, cout);
  // 
  // int N, M;
  // in >> N >> M;
  // vector< vector<int> > matAdi(N, vector<int>(N));
  // read_matadi(matAdi, M, in);
  // cout << "Transition function table:\n";
  // show_matadi(matAdi, cout);
  // 
  // int start_state;
  // in >> start_state;
  // cout << "Start state: ";
  // cout << start_state << '\n';
  // 
  // in >> n;
  // set<int> final_states;
  // read_set(final_states, n, in);
  // cout << "Final state set: ";
  // show_set(final_states, cout);
  // 
  // in >> n;
  // vector<int> word(n);
  // read_vector(word, n, in);
  // cout << "Word: ";
  // show_vector(word, cout);
  // cout << '\n';
  // 
  // cout << "Processing...\n";
  
  
  return 0;
}