#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[])
{
	int v[] = { 1, 2, 4, 2, 3, 2, 4, 3, 3, 5, 3 };
	
	for (unsigned i = 0; i < sizeof(v) / 4; i++)
		printf("%d ", v[i]);
	printf("\n");
	
	int *set = (int*)calloc(sizeof(v), sizeof(int));
	unsigned count = 0;
	
	for (unsigned i = 0; i < sizeof(v) / 4; i++)
	{
		bool exists = false;
		for (unsigned j = 0; j < count; j++)
		{
			if (set[j] == v[i])
			{
				exists = true;
				break;
			}
		}
		
		if (!exists)
		{
			set[count] = v[i];
			count++;
		}
	}
	
	for (unsigned i = 0; i < count; i++)
		printf("%d ", set[i]);
	printf("\n");
	
	return 0;
}
