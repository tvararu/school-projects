#include <stdio.h>

int main (int argc, char const *argv[])
{
	int n = 1345, k = 3;
	
	int a = 1;
	a <<= k - 1;
	
	if (!(n & a))
		n += a;
		
	printf("%d\n", n);
	
	return 0;
}
