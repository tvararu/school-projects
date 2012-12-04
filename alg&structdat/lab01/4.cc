#include <iostream>
using namespace std;

void print (int *v)
{
	for (unsigned i = 0; i < sizeof (v); i++)
		cout << v[i] << ' ';
	cout << '\n';
}

void selectionSort (int *v)
{
	int len = (int)sizeof(v);
	
	for (int i = 0; i < len - 1; i++)
	{
		int minIndex = i, min = v[i];
		for (int j = i + 1; j < len; j++)
		{
			if (min > v[j])
			{
				min = v[j];
				minIndex = j;
			}
		}
		
		if (minIndex != i)
			swap (v[i], v[minIndex]);
	}
}

int main (int argc, char const *argv[])
{
	int v[] = { 3, 2, 1, 5, 7, 8, 9, 2 };
	
	print (v);
	
	selectionSort (v);
	
	print (v);
	
	return 0;
}
