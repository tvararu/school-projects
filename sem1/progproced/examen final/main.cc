#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void resize (float **&v, int &n, int &m) {
	v = (float**)calloc(n, sizeof(float*));
	for (int i = 0; i < n; i++) {
		v[i] = (float*)calloc(m, sizeof(float));
	}
}

void foo (float **&v, const int &n) {
	float sum = 0;
	
	for (int k = 0, i = 0, j = 0, steps = n - 1; k < ((n + 1) / 2); k++, i = k, j = k, sum = v[i][i], steps -= 2) {
		if (steps <= 0) { printf("%f\n", sum); continue; }
		//right,	ex.: 01, 02, 03, 04
		for (int s = 0; s < steps; s++)			{ sum += v[i][++j]; }
		//down,		ex.: 14, 24, 34, 44
		for (int s = 0; s < steps; s++)			{ sum += v[++i][j]; }
		//left,		ex.: 43, 42, 41, 40
		for (int s = 0; s < steps; s++)			{ sum += v[i][--j]; }
		//up,			ex.: 30, 20, 10. Fara 00 pentru ca l-am pus la inceput.
		for (int s = 0; s < steps - 1; s++)	{ sum += v[--i][j]; }
		printf("%f\n", sum);
	}
}

int main (int argc, char const *argv[]) {
	clock_t start, finish;
	start = clock();
	// float **v;
	int n = 10;
	float v[10][10]
	
	// resize(v, n, n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[i][j] = i + j;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%f ", v[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	foo (v, n);
	
	finish = clock();
	
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf\n", duration);
	
	return 0;
}