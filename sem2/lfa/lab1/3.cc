#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
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
  if (v.size() == 0) {
    out << "(null word)\n";
    return;
  }
  
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
    out << '\n';
  }
}

void show_queue (queue<int> q, ostream &out) {
  while (q.size()) {
    cout << q.front() << ' ';
    q.pop();
  }
  cout << '\n';
}

vector<int> execute (set<int> &state, set<int> &alphabet, vector< vector<int> > foo, const int &start_state, set<int> &final_states, vector<int> &word) {
  vector<int> results, invalid;
  
  queue<int> st;
  st.push(start_state);
  
  while (word.size() == 0) {    
    // this should cover the edge case where the null word is a valid solution
    bool valid = false;
    
    cout << "Queue contents: ";
    show_queue(st, cout);
    int steps = 1;
    while (steps--) {
      int state = st.front();
      cout << "From state " << state << ", trying to use alpha" << '\n';
      st.pop();
      for (unsigned j = 0; j < foo[state].size(); j++) {
        if (foo[state][j] == -1) {
          cout << "Pushing " << j << " through alpha" << "\n";
          st.push(j);
          // check if j is a final state
          if (final_states.find(j) != final_states.end()) {
            valid = true;
            break;
          }
        }
      }
    }
    
    if (!st.size() || valid) {
      break;
    }
  }
  
  for (unsigned i = 0; i < word.size(); i++) {
    if (alphabet.find(word[i]) == alphabet.end()) {
      return invalid;
    }
    
    cout << "Queue contents: ";
    show_queue(st, cout);
    int steps = (int)st.size();
    while (steps--) {
      int state = st.front();
      cout << "From state " << state << ", using letter " << word[i] << '\n';
      st.pop();
      for (unsigned j = 0; j < foo[state].size(); j++) {
        if (foo[state][j] == word[i]) {
          cout << "Pushing " << j << "\n";
          st.push(j);
        }
        if (foo[state][j] == -1) {
          cout << "Pushing " << j << " through alpha" << "\n";
          st.push(j);
        }
      }
    }
    
    if (!st.size()) {
      break;
    }
  }
  
  while (st.size()) {
    results.push_back(st.front());
    st.pop();
  }
  
  return results;
}

int main (int argc, char const *argv[])
{
  ifstream in ("input3.in");
  // nota despre implementare: alpha este tratat ca -1
  // disclaimer: nu sunt sigur ca am tratat toate cazurile posibile cu implementarea asta
  
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
  
  int N, M;
  in >> N >> M;
  vector< vector<int> > foo(N, vector<int>(N));
  read_matadi(foo, M, in);
  cout << "Transition function table:\n";
  show_matadi(foo, cout);
  
  int start_state;
  in >> start_state;
  cout << "Start state: ";
  cout << start_state << '\n';
  
  in >> n;
  set<int> final_states;
  read_set(final_states, n, in);
  cout << "Final state set: ";
  show_set(final_states, cout);
  
  vector< vector<int> > words;
  while (in >> n) {
    vector<int> word(n);
    read_vector(word, n, in);
    cout << "Word: ";
    show_vector(word, cout);
    words.push_back(word);
  }
  
  in.close();
  
  cout << "\nProcessing...\n";
  
  for (unsigned i = 0; i < words.size(); i++) {
    vector<int> word = words[i];
    
    vector<int> results = execute(state, alphabet, foo, start_state, final_states, word);
    
    bool valid = false;
    for (unsigned i = 0; i < results.size(); i++) {
      if (final_states.find(results[i]) != final_states.end()) {
        valid = true;
        break;
      }
    }
    
    if (valid) {
      cout << "Possible end states include a final state. Word is valid: ";
    } else {
      cout << "Could not reach a final state. Word is invalid: ";
    }
    show_vector(word, cout);
    cout << '\n';
  }
  
  return 0;
}