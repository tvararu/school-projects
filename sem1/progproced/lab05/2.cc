#include <stdio.h>

int main (int argc, char const *argv[])
{
	int n = 10, oglinda = 0;
	
	while (n)
	{	
		oglinda <<= 1;
		if (n % 2)
			oglinda++;
		n >>= 1;
	}
	
	printf("%d\n", oglinda);
	
	return 0;
}
