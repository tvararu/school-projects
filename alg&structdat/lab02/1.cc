#include <iostream>
using namespace std;

//punctul a.
int getMax (int *vector, const int &length)
{
	int max = -0x7fffffff;
	for (int i = 0; i < length; i++)
		if (max < vector[i])
			max = vector[i];
			
	return max;
}

//punctul b.
int getMinPos (int *vector, const int &length)
{
	int min = 0x7fffffff, minPos;
	for (int i = 0; i < length; i++)
		if (min > vector[i])
		{
			min = vector[i];
			minPos = i;
		}
			
	return minPos;
}

int main (int argc, char const *argv[])
{
	int A[10] = { -400, 2, 3, 4, 6, 23, 11111111, 2 }, n = 8;
	
	cout << getMax (A, n) << '\n';
	
	cout << getMinPos (A, n) << '\n';
	
	return 0;
}