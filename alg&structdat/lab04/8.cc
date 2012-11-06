#include <iostream>
using namespace std;

struct node
{
	int info;
	node *next;
};

void printList (node *head)
{
	node *conductor = head;
	
	while (conductor->next)
	{	
		conductor = conductor->next;
		cout << conductor->info << ' ';
	}
	cout << '\n';
}

void game (node *head, const int &K)
{
	node *conductor = head, *prev = head;
	
	int step = 0;
	
	while (conductor->next)
	{
		step++;
		cout << conductor->next->info << ' ';
		if (step == K)
		{
			cout << "! => ";
			step = 0;
			
			node *target = conductor->next;
			if (!conductor->next->next)
				conductor->next = head;
			else
				conductor->next = conductor->next->next; // this bullshit here, for the edge case when we have to delete the last element in the list
			delete target;
			printList(head);
		}
		prev = conductor;
		conductor = conductor->next;
		if (!conductor->next)
			conductor = head;
		
		if (prev->info == conductor->info)
			break;
	}
	// printList(head);
}

int main (int argc, char const *argv[])
{
	node *head = new node;
	head->next = 0;
	
	const int N = 12, K = 7;
	
	// generate list
	node *prev = head;
	for (int i = 1; i <= N; i++)
	{
		node *conductor = new node;
		conductor->info = i;
		conductor->next = 0;
		
		prev->next = conductor;
		prev = conductor;
	}
	
	printList(head);
	
	game(head, K);
	
	return 0;
}
