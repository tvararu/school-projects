#include <iostream>
using namespace std;

int maxim (int *v, int lo, int hi)
{
	if (lo == hi)
		return v[lo];
	if ((hi - lo) == 1)
		return max (v[lo], v[hi]);
	
	int mid = lo + (hi - lo) / 2;
	return max (maxim(v, lo, mid), maxim(v, mid, hi));
}

int main (int argc, char const *argv[])
{
	int v[] = { 5, 3, 2, 1, 3, 4, 5, 6, 7 };
	
	cout << maxim (v, 0, sizeof(v) / 4);
	
	return 0;
}
