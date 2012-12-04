// Citesti dintr-un fisier text "INSERARE" si un sir de numere, despartite ori prin spatiu, ori prin virgula, ori prin punct si virgula, si le adauga intr-un arbore binar. Search dupa valoare, delete, afisare in consola si in fisier text, eventual sub forma de arbore. Afisari in RSD, RDS, SDR, radacina stanga dreapta etc.
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[])
{
	freopen ("fisier.in", "r", stdin);
	
	char buffer[255];
	scanf ("%s\n", &buffer);
	
	printf("%s\n", buffer);
	
	return 0;
}
