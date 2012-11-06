#include <stdio.h>

int main (int argc, char const *argv[])
{
	int n = 20, counter = 0;
	
	while (n)
	{
		if (n % 2)
			counter++;
		n >>= 1;
	}
	
	printf("%d\n", counter);
	
	return 0;
}
