#include <stdio.h>

int manna (int x)
{
	if (x >= 12)
		return x - 1;
	else
		return manna (manna (x + 2));
}

int main (int argc, char const *argv[])
{
	int n = 5;
	
	int x = manna(n);
	printf("%d\n", x);
	
	return 0;
}
