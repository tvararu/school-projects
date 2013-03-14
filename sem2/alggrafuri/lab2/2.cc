#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main (int argc, char const *argv[])
{
  ifstream in ("sortaret.in");
  
  int n, m; in >> n >> m;
  
  vector< vector<int> > liAd(n + 1);
  vector<int> gradIntern(n + 1);
  
  int x, y;
  while (in >> x >> y) {
    liAd[x].push_back(y);
    gradIntern[y]++;
  }
  
  queue<int> coada;
  vector<bool> visited(n + 1);
  fill (visited.begin(), visited.end(), 0);
  
  for (int i = 1; i <= n; i++) {
    if (gradIntern[i] == 0) {
      coada.push(i);
      visited[i] = true;
    }
  }
  
  ofstream out ("sortaret.out");
  while (!coada.empty()) {
    int nod = coada.front();
    coada.pop();
    out << nod << ' ';
    
    for (unsigned i = 0; i < liAd[nod].size(); i++) {
      gradIntern[liAd[nod][i]]--;
      if (gradIntern[liAd[nod][i]] == 0 && !visited[liAd[nod][i]]) {
        coada.push(liAd[nod][i]);
        visited[liAd[nod][i]] = true;
      }
    }
  }
  out.close();
  
  return 0;
}