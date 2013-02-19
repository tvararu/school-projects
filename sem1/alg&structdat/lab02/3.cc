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

void stergere (int *vector, int &length, const int &pos)
{	
	cout << "Stergem valoarea elementului de la pozitia " << pos << ".\n";
	
	length--;
	for (int i = pos; i < length; i++)
	{
		vector[i] = vector[i + 1];
	}
}

int main (int argc, char const *argv[])
{
	int A[100] = { -400, 2, 3, 4, 6, 23, 11111111, 2 }, n = 8;
	
	show (A, n);
	
	int pos = 4;
	stergere (A, n, pos);
	
	show (A, n);	
	
	return 0;
}
