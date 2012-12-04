#include <stdio.h>

int ack (int n, int m)
{
	// printf("%d %d\n", n, m);
	if (n == 0)
		return m + 1;
	if (m == 0)
		return ack (n - 1, 1);
	return ack (n - 1, ack (n, m - 1));
}

int main (int argc, char const *argv[])
{
	int n = 2, m = 3;
	
	printf("%d\n", ack(n, m));
	
	return 0;
}
