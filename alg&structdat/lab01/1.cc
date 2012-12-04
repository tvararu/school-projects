#include <iostream>
using namespace std;

void print (int *v)
{
	for (unsigned i = 0; i < sizeof (v); i++)
		cout << v[i] << ' ';
	cout << '\n';
}

void bubbleSort (int *v)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (unsigned i = 1; i < sizeof (v); i++)
		{
			if (v[i - 1] > v[i])
			{
				swap (v[i - 1], v[i]);
				sorted = false;
			}
		}
	}
}

int main (int argc, char const *argv[])
{
	int v[] = { 3, 2, 1, 5, 7, 8, 9, 2 };
	
	bubbleSort (v);
	
	print (v);
	
	return 0;
}
