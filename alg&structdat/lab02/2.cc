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

void insert (int *vector, int &length, const int &val, const int &pos)
{	
	cout << "Inseram valoarea " << val << " la pozitia " << pos << ".\n";
	
	length++;
	for (int i = length; i > pos; i--)
	{
		vector[i] = vector[i - 1];
	}
	
	vector[pos] = val;
}

int main (int argc, char const *argv[])
{
	int A[100] = { -400, 2, 3, 4, 6, 23, 11111111, 2 }, n = 8;
	
	show (A, n);
	
	int val = 17, pos = 4;
	insert (A, n, val, pos);
	
	show (A, n);	
	
	return 0;
}
