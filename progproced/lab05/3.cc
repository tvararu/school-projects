#include <stdio.h>

int main (int argc, char const *argv[])
{
	int n = 1345, k = 3;
	
	int a = 1;
	while (--k)
	{
		a <<= 1;
	}
	
	if (!(n & a))
		n += a;
		
	printf("%d\n", n);
	
	return 0;
}
