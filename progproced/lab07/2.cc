// Primeste ca parametrii un set de numere si le returneaza in stdout sortate.
#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main (int argc, char const *argv[])
{
	int *numere = (int*)calloc(argc, sizeof(int));
		
	for (int i = 1; i < argc; i++)
	{
		numere[i - 1] = atoi(argv[i]);
	}
	
	qsort (numere, argc, sizeof(int), compare);
	
	for (int i = 1; i < argc; i++)
	{
		printf("%d ", numere[i]);
	}
	printf("\n");
	
	return 0;
}
