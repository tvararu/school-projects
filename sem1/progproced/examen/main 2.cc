#include <cstdio>
#include <ctime>
using namespace std;

long long random_num()
{
	long long num = 0;
	int aleat = rand();
	num += aleat;
	num <<= 32;
	aleat = rand();
	num += aleat;
	
	return num;
}

int line_count(FILE *in)
{
	int num_lines = 0;
	char ch = 0;
	while ((ch = fgetc(in)) != EOF)
	{
		if (ch == '\n')
			++num_lines;
	}
	++num_lines;
	
	return num_lines;
}

void read(char **&v, const int &n)
{
	v = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
		v[i] = (char*)calloc(50, sizeof(char));
	
	freopen("intrare.txt", "r", stdin);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", v[i]);
	}
	fclose(stdin);
}

void generate_rands(long long *&rands, const int &n)
{
	for (int i = 0; i < n; i++)
		rands[i] = random_num();
}

void output_rands(char **&persoane, const int &n, long long *&rands)
{
	FILE *out;
	out = fopen("output.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(out, "%s %lld\n", persoane[i], rands[i]);
	}
	fclose(out);
}

int pow2(const int &n)
{
	int p = 1;
	p <<= n;
	return p;
}

void solve(char **&persoane, const int &n, long long *&rands)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if ( (rands[i] & pow2(j)) && (rands[j] & pow2(i)) )
				{
					printf("(%s, %s)\n", persoane[i], persoane[j]);
					rands[i] -= pow2(j);
					rands[j] -= pow2(i);
				}
			}
		}
	}
}

int main (int argc, char const *argv[])
{
	srand(time(0));
	// printf("%lu\n", sizeof(rand())); // returneaza 4 pe g++ 4.2 sub OS X
	
	char **persoane;
	
	FILE *lc;
	lc = fopen("intrare.txt", "r");
	int lines = line_count(lc);
	fclose(lc);
	
	read(persoane, lines);
	
	long long *rands;
	rands = (long long*)calloc(lines, sizeof(long long));
	generate_rands(rands, lines);
	
	output_rands(persoane, lines, rands);
	
	solve(persoane, lines, rands);
	
	return 0;
}