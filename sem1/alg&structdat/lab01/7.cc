#include <iostream>
using namespace std;

void print (int *v)
{
	for (unsigned i = 0; i < 11; i++)
		cout << v[i] << ' ';
	cout << '\n';
}

int binSearch (int *v, int lo, int hi, const int &needle)
{
	for (int i = lo; i < hi; i++)
	{
		int mid = lo + (hi - lo) / 2;
		
		if (v[mid] == needle)
			return mid;
		else if (v[mid] > needle)
			return binSearch (v, lo, mid, needle);
		else
			return binSearch (v, mid, hi, needle);
	}
	
	return -1;
}

int main (int argc, char const *argv[])
{
	int v[] = { 1, 2, 2, 2, 2, 3, 4, 5, 6, 8, 9 };
	
	print (v);
	
	cout << binSearch (v, 0, 11, 5) << '\n';
	
	return 0;
}
