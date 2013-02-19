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
	return sqrt ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main (int argc, char const *argv[])
{
	srand (time (0));
	
	o.x = 0;	o.y = 0;
	c.x = 0.5;	c.y = 0.5;
	
	int n = 4000000, count;
	
	for (int i = n; i > 0; i--)
	{
		punct p;
		p.x = (float)rand () / RAND_MAX;
		p.y = (float)rand () / RAND_MAX;
		
		if (dist (p, c) <= 0.5) 
			count++;
	}
	
	float pi = (float)(4 * count)
	
	printf ("%d / %d = %f\n", n, count, pi);
	
	cout.precision(200);
	cout << M_PI << endl;
	
	return 0;
}
