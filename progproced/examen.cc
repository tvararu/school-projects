#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

struct elev
{
	char nume[255];
	char prenume[255];
	int grupa;
	int nota;
};

int compare_grupe (const void * a, const void * b)
{
	typeof(*(elev*)a) x = *(elev*)a;
	typeof(*(elev*)b) y = *(elev*)b;
	return (x.grupa - y.grupa);
}

int compare_note (const void * a, const void * b)
{
	typeof(*(elev*)a) x = *(elev*)a;
	typeof(*(elev*)b) y = *(elev*)b;
	return (y.nota - x.nota);
}

int compare_nume (const void * a, const void * b)
{
	typeof(*(elev*)a) x = *(elev*)a;
	typeof(*(elev*)b) y = *(elev*)b;
	return strcmp(x.nume, y.nume);
}

int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int random_nota ()
{
	return ((int)rand() % 10) + 1;
}

void citire (elev *studenti, const int &size)
{
	for (int i = 0; i < size; i++)
	{
		char nume[255]; scanf("%s", nume);
		char prenume[255]; scanf("%s", prenume);
		int grupa; scanf("%d", &grupa);
		
		strcpy(studenti[i].nume, nume);
		strcpy(studenti[i].prenume, prenume);
		studenti[i].grupa = grupa;
		
		int nota = random_nota();
		studenti[i].nota = nota;
	}
}

void afisare (elev *studenti, const int &size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s %s %d %d\n", studenti[i].nume, studenti[i].prenume, studenti[i].grupa, studenti[i].nota);
	}
	printf("\n");
}

int main (int argc, char const *argv[])
{
	srand(time(0));
	
	freopen("studenti.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	
	elev *studenti = (elev*)calloc(N, sizeof(elev));
	
	citire(studenti, N);
	
	// afisare(studenti, N);
	
	// sortare in functie de grupe
	qsort(studenti, N, sizeof(elev), compare_grupe);
	// afisare(studenti, N);
	
	// sortare in functie de note
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		if (studenti[i].grupa != studenti[i - 1].grupa)
		{
			qsort(studenti + count, i - count, sizeof(elev), compare_note);
			count = i;
		}
	}
	afisare(studenti, N);
	
	return 0;
}