#include <iostream>
using namespace std;

struct node
{
	int info;
	node *next;
};

void prepend (node *head, const int &value)
{
	node *add = new node;
	add->info = value;
	add->next = head->next;
	head->next = add;
}

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

void insertArithmeticMean (node *head)
{
	node *conductor = head->next, *prev = head;
	while (conductor->next)
	{
		prev = conductor;
		conductor = conductor->next;
		node *mean = new node;
		mean->info = (prev->info + conductor->info) / 2;
		prev->next = mean;
		mean->next = conductor;
	}
}

int main (int argc, char const *argv[])
{
	node *head = new node;
	head->next = 0;
	
	prepend (head, 64);
	prepend (head, 128);
	prepend (head, -18);
	prepend (head, 256);
	prepend (head, 4);
	prepend (head, 3);
	prepend (head, 2);
	prepend (head, 27);
	
	printList (head);
	
	insertArithmeticMean (head);
	
	printList (head);
	
	return 0;
}
