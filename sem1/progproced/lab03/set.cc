#include <cstdlib>
#include <cstdio>

void print (int *v, const int &n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int compare (const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}

int main (int argc, char const *argv[])
{
	int v[] = { 13, 1, 2, 4, 6, 3, 4, 4, 2, 2, 5, 5, 2 };
	int n = sizeof(v) / sizeof(int);
	
	print(v, n);
	
	qsort(v, n, sizeof(int), compare);
	
	print(v, n);
	
	int numDistinct = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (v[i] != v[i - 1])
			numDistinct++;
	}
	
	// printf("%d\n", numDistinct);
	
	int *set;
	set = (int*)calloc(numDistinct, sizeof(int));
	
	for (int i = 0, j = 0; i < n; i++)
	{
		if (v[i] != v[i - 1])
		{
			set[j] = v[i];
			j++;
		}
	}
	
	print(set, numDistinct);
	
	return 0;
}
