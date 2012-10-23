#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;

struct punct
{
	float x;
	float y;
} o, c;

float dist (punct &a, punct &b)
{
	// radical din ( (x1 ^ 2 - x2 ^ 2) + (y1 ^ 2 - y2 ^ 2) )
	return sqrt ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main (int argc, char const *argv[])
{
	srand (time (0)); // seed random cu o valoare determinata de timpul rularii programului, ca sa genereze alte numere aleatorii la fiecare executare
	
	o.x = 0;	o.y = 0; // o, centrul axei
	c.x = 0.5;	c.y = 0.5; // c, centrul unui cerc de raza 0.5 cu originea in (0.5, 0.5); diametru 1.0. De asemenea, ne imaginam si un patrat circumscris cu latura de 1.0
	
	int n = 4000000, count;
	
	for (int i = n; i > 0; i--)
	{
		// generam puncte cu coordonate x si y random
		punct p;
		p.x = (float)rand () / RAND_MAX;
		p.y = (float)rand () / RAND_MAX; // cast in float ca sa calculeze C-ul cum trebuie
		
		if (dist (p, c) <= 0.5) // numaram cate puncte generate aleator se afla in interiorul cercului
			count++;
	}
	
	float pi = (float)(4 * count) / n; // magie. Relatia dintre suprafata cercului si a patratului circumscris cercului determina pi
	
	printf ("%d / %d = %f\n", n, count, pi);
	
	cout.precision(200);
	cout << M_PI << endl;
	
	return 0;
}
