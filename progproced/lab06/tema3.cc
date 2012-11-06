#include <stdio.h>

int **v, n = 0, m = 0;

void resize ()
{
	v = (int**)calloc(n + 1, sizeof(int*));
	for (int i = 0; i < n; i++)
		v[i] = (int*)calloc(m, sizeof(int));
}

void normal_print ()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}
}

void spiral_print ()
{
	int i = 0, j = 0, rightMax = m - 1, downMax = n - 1, leftMax = 0, upMax = 0, printfs = n * m;
	char direction = 'R';
	while (printfs--)
	{
		printf("%d ", v[i][j]);
		switch (direction)
		{
		case 'R':
			if (++j > rightMax)
			{
				--j;
				direction = 'D';
				++upMax;
				++i;
			}
		break;
		case 'D':
			if (++i > downMax)
			{
				--i;
				direction = 'L';
				--rightMax;
				--j;
			}
		break;
		case 'L':
			if (--j < leftMax)
			{
				++j;
				direction = 'U';
				--downMax;
				--i;
			}
		break;
		case 'U':
			if (--i < upMax)
			{
				++i;
				direction = 'R';
				++leftMax;
				++j;
			}
		break;
		}
	}
}

void read ()
{
	freopen("fisier.in", "r", stdin);
	scanf("%d %d", &n, &m);
	
	resize();
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &v[i][j]);
	
	fclose(stdin);
}

int main (int argc, char const *argv[])
{
	read();
	// normal_print();
	spiral_print();
	
	return 0;
}
