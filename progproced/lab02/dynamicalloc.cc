#include <cstdio>

int main ()
{
	int *v;
	int n = 100;
	
	// v = (int*)malloc(n * sizeof(int));
	v = (int*)calloc(n, sizeof(int));
	
	for (int i = 1; i <= n; i++)
	{
		v[i] = i;
	}
	
	int *w = &v[0];
	
	for (int i = 1; i <= n; i++)
	{
		printf ("%d ", w[i]);
	}
	
	free (v);
	
	return 0;
}
