#include <iostream>
using namespace std;

void print (int *v)
{
	for (unsigned i = 0; i < sizeof (v); i++)
		cout << v[i] << ' ';
	cout << '\n';
}

void insertionSort (int *v)
{
	// memcpy (destinatia, sursa, cantitatea);
	
	for (int i = 1; i < (int)sizeof (v); i++)
	{
		int index = i - 1, num = v[i], amount = 0;
		while (v[index] > num && index >= 0)
		{
			amount++;
			index--;
		}
		if (amount)
			memcpy (v + index + 2, v + index + 1, amount * sizeof (int));
		v[index + 1] = num;
	}
}

int main (int argc, char const *argv[])
{
	int v[] = { 3, 2, 1, 5, 7, 8, 9, 2 };
	
	print (v);
	
	insertionSort (v);
	
	print (v);
	
	return 0;
}
