#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[])
{
	int v[] = { 1, 2, -4, 2, 3, -2, 4, -3, -3, 5, 3 };
	
	for (unsigned i = 0; i < sizeof(v) / 4; i++)
		printf("%d ", v[i]);
	printf("\n");
	
	unsigned numarul_componentelor_pare = 0;
	unsigned suma_elementelor_pozitive = 0;
	int cel_mai_mare_numar_negativ = -0x7fffffff;
	
	for (unsigned i = 0; i < sizeof(v) / 4; i++)
	{
		if (v[i] >= 0)
		{
			numarul_componentelor_pare++;
			suma_elementelor_pozitive += v[i];
		}
		else if (v[i] > cel_mai_mare_numar_negativ)
			cel_mai_mare_numar_negativ = v[i];
	}
	
	printf("Numarul componentelor pare: %d\n", numarul_componentelor_pare);
	printf("Suma elementelor pozitive: %d\n", suma_elementelor_pozitive);
	printf("Cel mai mare numar negativ: %d\n", cel_mai_mare_numar_negativ);
	
	return 0;
}
