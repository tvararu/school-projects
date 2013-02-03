#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector< vector<int> > matAdi;

int main (int argc, char const *argv[])
{
	// Input-ul este de forma celui descris in problema aceasta:
	// http://infoarena.ro/problema/royfloyd
	ifstream in ("royfloyd.in");
	in >> n;
	matAdi.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			in >> matAdi[i][j];
	}
	in.close();
	
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 		cout << matAdi[i][j] << ' ';
	// 	cout << '\n';
	// }
	
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (	i != j && matAdi[i][k] && matAdi[k][j] &&
						(matAdi[i][j] > matAdi[i][k] + matAdi[k][j] || !matAdi[i][j]) )
					matAdi[i][j] = matAdi[i][k] + matAdi[k][j];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matAdi[i][j] << ' ';
		cout << '\n';
	}
		
	return 0;
}
