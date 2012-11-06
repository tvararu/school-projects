#include <stdio.h>
#include <stdlib.h>

int ciur[500];

void make_ciur (const int &n)
{
	for (int i = 2; i <= n / 2; i++)
	{
		if (!ciur[i])
		{
			ciur[i] = 1;
			for (int j = i + i; j <= n / 2; j += i)
			{
				ciur[j] = 2;
			}
		}
	}
}

int prim (const int &k)
{
	return (ciur[k] == 1);
}

int main (int argc, char const *argv[])
{
	int n = 55;
	
	ciur[1] = 1;
	make_ciur(n);
	
	for (int i = 2; i <= n / 2; i++)
	{
		if (!(n % i) && prim(i))
			printf("%d\n", i);
	}
	
	return 0;
}
