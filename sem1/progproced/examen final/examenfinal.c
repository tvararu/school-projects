#include <stdio.h>

char* sievify (char *ciur, const int n) {
	ciur = (char*)calloc(sizeof(char), n);
	int i;
	for (i = 2; i < n; i++) {
		if (!ciur[i]) {
			int j;
			for (j = i + i; j < n; j += i) {
				ciur[j] = 1;
			}
		}
	}
	
	return ciur;
}

int main (int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	
	freopen(argv[2], "w", stdout);
	int i;
	for (i = 1; i < n; i++) {
		printf("%d ", i);
	}
	fclose(stdout);
	
	freopen(argv[2], "r", stdin);
	freopen(argv[3], "w", stdout);
	
	char *ciur = sievify(ciur, n);
	
	while (n--) {
		int x;
		scanf("%d", &x);
		if (!ciur[x]) {
			printf("%d\n", x);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}