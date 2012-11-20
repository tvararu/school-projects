// Primeste din fisier un sir de numere, le imparte in numere pare si impare, si apoi numerele pare le face o apelare a programului 2 cu numerele pare, si apoi o apelare cu numerele impare.
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[])
{
	freopen("1.in", "r", stdin);
	int n;
	scanf("%d", &n);
	int *v = (int*)calloc(n, sizeof(int));
	
	int impare = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
		if (v[i] % 2)
			impare++;
	}
	
	// for (int i = 0; i < n; i++)
	// {
	// 	printf("%d\n", v[i]);
	// }
	
	int *par = (int*)calloc(n - impare, sizeof(int));
	int *impar = (int*)calloc(impare, sizeof(int));
	
	int parCount = 0, imparCount = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] % 2)
			impar[imparCount++] = v[i];
		else
			par[parCount++] = v[i];
	}
	
	// for (int i = 0; i < parCount; i++)
	// {
	// 	printf("%d\n", par[i]);
	// }
	// 
	// for (int i = 0; i < imparCount; i++)
	// {
	// 	printf("%d\n", impar[i]);
	// }
	
	char path[] = "./2.cc.out";
	
	char strPare[255];
	
	for (int i = 0; i < parCount; i++)
	{
		char numar[10];
		/* Gandirea initiala:
		strcat(strPare, " ");
		itoa (par[i], numar, 10);
		strcat(strPare, numar);
		*/
		sprintf(numar, " %d", par[i]); // pentru ca itoa e apparently non-standard si nu e inclus nici in gcc nici in clang sub Linux/OS X; http://stackoverflow.com/questions/190229/where-is-the-itoa-function-in-linux
		strcat(strPare, numar);
	}
	
	char pathPare[255];
	strcat(pathPare, path);
	strcat(pathPare, strPare);
	
	printf("%s\n", pathPare);
	
	char strImpare[255];
	
	for (int i = 0; i < imparCount; i++)
	{
		char numar[10];
		sprintf(numar, " %d", impar[i]);
		strcat(strImpare, numar);
	}
	
	char pathImpare[255];
	strcat(pathImpare, path);
	strcat(pathImpare, strImpare);
	
	printf("%s\n", pathImpare);
	
	printf("%s\n", (char*)system(pathPare));
	printf("%s\n", (char*)system(pathImpare));
	
	return 0;
}