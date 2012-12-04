#include <cstdio>

int main (int argc, char const *argv[])
{
	int n = 1024;
	
	// forma binara a unui numar putere a lui 2, 1024 de exemplu:   0100 0000 0000
	// forma binara a unui numar putere a lui 2 fara 1, 1024 - 1:   0011 1111 1111
	// operatorul bitwise & functioneaza ca si-ul logic, n & n - 1: 0000 0000 0000 = 0
	
	if ( n & (n - 1) )
		printf ("%d nu este putere a lui 2.\n", n);
	else
		printf ("%d este putere a lui 2.\n", n);
	
	return 0;
}