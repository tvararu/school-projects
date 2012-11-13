#include <stdio.h>

struct node
{
	int info;
	node *next;
	node()
	{
		info = 0;
		next = 0;
	}
};

void read (node *lista)
{
	freopen("fisier.in", "r", stdin);
	int n = 0;
	scanf("%d", &n); //printf("%d\n", n);
	
	node *conductor = lista;
	while (n--)
	{
		int val = 0;
		scanf("%d", &val); //printf("%d\n", val);
		node *add = (node*)calloc(5, sizeof(int));
		add->info = val;
		conductor->next = add;
		conductor = conductor->next;
	}
	
	fclose(stdin);
}

void print (node *lista)
{
	node *conductor = lista;
	while (conductor->next)
	{
		conductor = conductor->next;
		printf("%d ", conductor->info);
	}
	printf("\n");
}

int search (const int &a, node *lista)
{
	node *conductor = lista;
	int count = 0;
	while (conductor->next)
	{
		count++;
		conductor = conductor->next;
		if (conductor->info == a)
			return count;
	}
	return -1;
}

int main (int argc, char const *argv[])
{
	node *list = (node*)calloc(5, sizeof(int));
	read (list);
	
	print (list);
	
	printf("%d\n", search(9, list));
	printf("%d\n", search(13, list));
	
	return 0;
}
