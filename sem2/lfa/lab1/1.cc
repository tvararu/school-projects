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

void read_matrix (vector< vector<int> > &v, const int &m, const int &n, istream &in) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      in >> v[i][j];
    }
  }
}

void show_matrix (vector< vector<int> > &v, const int &m, const int &n, ostream &out) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      out << v[i][j] << ' ';
    }
    cout << '\n';
  }
}

int execute (set<int> &state, set<int> &alphabet, vector< vector<int> > foo, const int &start_state, set<int> &final_states, vector<int> &word) {
  bool invalid = false;
  unsigned st = start_state;
  for (unsigned i = 0; i < word.size(); i++) {
    if (alphabet.find(word[i]) != alphabet.end()) {
      cout << word[i] << " is a part of the alphabet. ";
    } else {
      invalid = true;
      cout << word[i] << " is an invalid character, breaking.\n";
      break;
    }
    
    if ((st < 0 || st >= foo.size()) || ((unsigned)word[i] >= foo[0].size())) {
      invalid = true;
      cout << "Transition a[" << st << "]["<< word[i] << "] does not exist, breaking.\n";
      break;
    }
    cout << "Transition a[" << st << "]["<< word[i] << "].\n";
    
    st = foo[st][word[i]];
  }
  
  return (invalid) ? -1 : st;
}

int main (int argc, char const *argv[])
{
  ifstream in ("input1.in");
  
  int n;
  
  in >> n;
  set<int> state;
  read_set(state, n, in);
  cout << "State set: ";
  show_set(state, cout);
  
  in >> n;
  set<int> alphabet;
  read_set(alphabet, n, in);
  cout << "Input alphabet: ";
  show_set(alphabet, cout);
  
  unsigned M, N;
  in >> M >> N;
  vector< vector<int> > foo(M, vector<int>(N));
  read_matrix(foo, M, N, in);
  cout << "Transition function table:\n";
  show_matrix(foo, M, N, cout);
  
  int start_state;
  in >> start_state;
  cout << "Start state: ";
  cout << start_state << '\n';
  
  in >> n;
  set<int> final_states;
  read_set(final_states, n, in);
  cout << "Final state set: ";
  show_set(final_states, cout);
  
  in >> n;
  vector<int> word(n);
  read_vector(word, n, in);
  cout << "Word: ";
  show_vector(word, cout);
  cout << '\n';
  
  in.close();
  
  cout << "Processing...\n";
  
  int result = execute(state, alphabet, foo, start_state, final_states, word);
  // returns -1 if word is invalid, final state otherwise
  
  if (final_states.find(result) != final_states.end()) {
    cout << "Word is valid.\n";
  } else {
    cout << "Word is invalid.\n";
  }
  
  return 0;
}