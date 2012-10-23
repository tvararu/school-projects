#include <iostream>
using namespace std;

void print (int *v)
{
	for (unsigned i = 0; i < sizeof (v); i++)
		cout << v[i] << ' ';
	cout << '\n';
}

int search (int *v, const int &needle)
{
	for (int i = 0; i < (int)sizeof(v); i++)
		if (v[i] == needle)
			return i;
	
	return -1;
}

int main (int argc, char const *argv[])
{
	int v[] = { 3, 2, 1, 5, 7, 8, 9, 2 };
	
	print (v);
	
	cout << search (v, 13) << '\n';
	
	return 0;
}
