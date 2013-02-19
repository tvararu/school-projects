#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	int to;
	int cost;
};

// mn = make node
inline node mn (const int &to, const int &cost)
{
	node nod;
	nod.to = to;
	nod.cost = cost;
	return nod;
}

bool operator< (const node &left, const node &right)
{
	if (left.cost != right.cost)
		return left.cost > right.cost;
	if (left.to != right.to)
		return left.to < right.to;
	return false;
}

int main (int argc, char const *argv[])
{
	// Input-ul este de forma celui descris in problema aceasta:
	// http://infoarena.ro/problema/dijkstra
	ifstream in ("dijkstra.in");
	int n, m; in >> n >> m;
	
	vector<int> start (n + 1);
	vector< vector<int> > liad (3, vector<int>(m + 1));
	for (int k = 1; k <= m; k++)
	{
		int x, y, c; in >> x >> y >> c;
		liad[0][k] = y;
		liad[1][k] = start[x];
		liad[2][k] = c;
		start[x] = k;
	}
	in.close ();
	
	// for (int i = 1; i <= n; i++)
	// {
	// 	cout << i << ": ";
	// 	for (int tar = start[i]; tar; tar = liad[1][tar])
	// 		cout << liad[0][tar] << ' ';
	// 	cout << '\n';
	// }	
	// cout << '\n';
	
	priority_queue<node> pq;
	
	pq.push ( mn (1, 0) );
	int INF = 0x7fffffff;
	vector<int> dist (n + 1, INF);
	
	while (!pq.empty())
	{
		node nod = pq.top ();
		pq.pop ();
		
		for (int target = start[nod.to]; target; target = liad[1][target])
		{
			if (dist[ liad[0][target] ] > nod.cost + liad[2][target])
			{
				dist[ liad[0][target] ] = nod.cost + liad[2][target];
				pq.push ( mn ( liad[0][target], dist[ liad[0][target] ]) );
			}
		}
	}
	
	for (int i = 2; i <= n; i++)
	{
		cout << ((dist[i] == INF) ? 0 : dist[i]) << ' ';
	}
	cout << '\n';
	
	return 0;
}
