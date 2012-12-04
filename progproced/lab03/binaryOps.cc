#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>

int main (int argc, char const *argv[])
{
	srand(time(0));
	int key = rand() % (1 << 8 /*lol*/ );
	printf("Key: %d\n", key);
	
	const char *c = "programare";
	char d[50];
	printf("Original:\t%s\n", c);
	
	//encrypt
	for (unsigned i = 0; i < strlen(c); i++)
	{
		d[i] = c[i] ^ key;
	}
	d[strlen(c)] = '\0';
	
	printf("Encrypted:\t%s\n", d);
	
	//decrypt
	for (unsigned i = 0; i < strlen(c); i++)
	{
		d[i] = d[i] ^ key;
	}
	
	printf("Decrypted:\t%s\n", d);
	
	return 0;
}
