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

int main (int argc, char const *argv[])
{
	node *head = new node;
	head->next = 0;
	
	return 0;
}
