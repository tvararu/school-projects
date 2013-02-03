#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N;
vector< vector<int> > matAdi;

int grad (const int &nod) {
	int grad = 0;
	for (int i = 0; i < N; i++) {
		grad += matAdi[i][nod] + matAdi[nod][i];
	}
	
	return grad;
}

int numarMuchii () {
	int numar = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			numar += matAdi[i][j];
		}
	}
	
	return numar;
}

int main (int argc, char const *argv[])
{
	ifstream in ("1.in");
	in >> N;
	matAdi.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			in >> matAdi[i][j];
	}
	in.close();
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << matAdi[i][j] << ' ';
		cout << '\n';
	}
	
	cout << grad(0) << '\n';
	
	cout << numarMuchii() << '\n';
	
	// cout << gradMax() << '\n';
	
	return 0;
}