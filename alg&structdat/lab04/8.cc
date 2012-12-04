#include <iostream>
using namespace std;

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

void print_circular_list (node *list)
{
	node *conductor = list->next;
	while (true)
	{
		cout << conductor->info << ' ';
		if (conductor->info >= conductor->next->info)
			break;
		conductor = conductor->next;
	}
	cout << endl;
}

void game (node *list, const int &k)
{
	node *conductor = list->next, *prev = list;
	int count = 1;
	while (true)
	{
		// cout << conductor->info << ' ';
		if (count == k)
		{
			// cout << '!' << endl;
			// cout << conductor->info << " is the target. ";
			if (conductor->info < prev->info)
			{
				// cout << "And it's also the head.\n";
				list->next = conductor->next;
			}
			
			node *target = conductor;
			conductor = conductor->next;
			delete target;
			prev->next = conductor;
			count = 1;
			
			// cout << "Deleted: ";
			// print_circular_list (list);
		}
		else
		{	
			prev = conductor;
			conductor = prev->next;
			count++;
		}
		if (conductor->info == conductor->next->info)
			break;
	}
	cout << conductor->info << endl;
}

int main (int argc, char const *argv[])
{
	node *list = new node;
	list->next = 0;
	
	const int N = 1000, K = 7;
	
	node *prev = list;
	for (int i = 1; i <= N; i++)
	{
		node *add = new node;
		add->info = i;
		prev->next = add;
		prev = add;
	}
	
	prev->next = list->next; // circular!
	
	// print_circular_list (list);
	
	game (list, K);
	
	return 0;
}
