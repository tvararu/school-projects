#include <stdio.h>

int main (int argc, char const *argv[])
{
	for (int i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	
	printf("%s\n", system("uptime"));
	
	/*
		1. Primeste din fisier un sir de numere, le imparte in numere pare si impare, si apoi numerele pare le face o apelare a programului 2 cu numerele pare, si apoi o apelare cu numerele impare.
		
		2. Primeste ca parametrii un set de numere si le returneaza in stdout sortate.
		
	*/
	
	return 0;
}
