#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main (int argc, char const *argv[])
{
  ifstream in ("dfs.in");
  
  int n, m; in >> n >> m;
  
  vector< vector<int> > liAd (n);
  
  int x, y;
  while (in >> x >> y) {
    x--; y--;
    liAd[x].push_back(y);
    liAd[y].push_back(x);
  }
  
  in.close();
  
  set<int> remaining;
  
  for (int i = 0; i < n; i++) {
    remaining.insert(i);
  }
  
  int nr = 0;
  
  queue<int> bfs;
  while (!remaining.empty()) {
    bfs.push(*remaining.begin());
    remaining.erase(remaining.begin());
    
    while (!bfs.empty()) {
      int nod = bfs.front();
      bfs.pop();
      
      for (unsigned i = 0; i < liAd[nod].size(); i++) {
        if (remaining.find(liAd[nod][i]) != remaining.end()) {
          bfs.push(liAd[nod][i]);
          remaining.erase(liAd[nod][i]);
        }
      }
    }
    nr++;
  }
  
  ofstream out ("dfs.out");
  out << nr << '\n';
  out.close();
  
  return 0;
}