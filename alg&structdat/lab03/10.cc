#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main (int argc, char const *argv[])
{
	ifstream in ("10.in");
	int n; in >> n;
	
	vector<int> a (n);
	
	for (int i = 0; i < n; i++)
	{
		in >> a[i];
	}
	in.close ();
	
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << '\n';
	
	int pickOne = -1, aparitii = 0;
	for (int i = 0; i < n; i++)
	{
		if (!aparitii)
		{
			// alegem primul numar pe care il gasim
			pickOne = a[i];
			aparitii = 1;
		}
		else if (a[i] == pickOne)
		{
			// am mai gasit unul ca el
			aparitii++;
		}
		else
		{
			// am gasit unul diferit
			aparitii--;
		}
	}
	
	if (pickOne == -1)
		cout << "Nu exista element majoritar.\n";
	
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == pickOne)
			count++;
	}
	
	if (count > (n / 2) + 1)
		cout << "Elementul majoritar exista si este " << pickOne << ".\n";
	else
		cout << "Nu exista element majoritar.\n";
	
	return 0;
}
