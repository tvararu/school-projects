#include <iostream>
using namespace std;

void show (int *vector, const int &length)
{
	for (int i = 0; i < length; i++)
	{
		cout << vector[i] << ' ';
	}
	cout << '\n';
}

void stergere (int *vector, int &length, int &pos)
{	
	length--;
	for (int i = pos; i < length; i++)
	{
		vector[i] = vector[i + 1];
	}
}

void removeDuplicates (int *vector, int &length)
{
	for (int i = 0; i < length; i++)
	{
		if (vector[i] == vector[i - 1])
			stergere (vector, length, i);
	}
}

int main (int argc, char const *argv[])
{
	int A[100] = { 1, 2, 3, 4, 4, 5, 6, 7, 7, 8, 9 }, n = 11;
	
	show (A, n);
	
	removeDuplicates(A, n);
	
	show (A, n);	
	
	return 0;
}
