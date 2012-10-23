#include <iostream>
using namespace std;

struct node
{
	int val;
	node *next;
} *head;

void printList ()
{
	if (!head->next)
	{
		cout << '\n';
		return;
	}
		
	node *conductor = head;
	
	while (conductor->next)
	{
		conductor = conductor->next;
		
		cout << conductor->val << ' ';
	}
	cout << '\n';
}

void prepend (const int &value)
{
	node *add = new node;
	add->val = value;
	
	if (head->next)
	{
		add->next = head->next;
		head->next = add;
	}
	else
	{
		head->next = add;
		add->next = 0;
	}
}

void insert (const int &value, int pos)
{
	if (!head->next || !pos) // list is empty OR we want to prepend
	{
		prepend (value);
		return;
	}
	
	node *conductor = head->next, *prev;
	
	while (pos && conductor->next)
	{
		prev = conductor;
		conductor = conductor->next;
		pos--;
	}
	
	node *add = new node;
	add->val = value;
	
	prev->next = add;
	add->next = conductor;
}

void append (const int &value)
{
	if (!head->next) // list is empty
	{
		prepend (value);
		return;
	}
	
	node *conductor = head->next;
	
	while (conductor->next)
	{
		conductor = conductor->next;
	}
	
	node *add = new node;
	add->val = value;
	add->next = 0;
	
	conductor->next = add;
}

int main (int argc, char const *argv[])
{
	head = new node;
	head->next = 0;
	
	prepend (5);
	prepend (4);
	prepend (3);
	prepend (2);
	printList ();
	
	insert (13, 1);
	printList ();
	
	insert (17, 4);
	printList ();
	
	append (8);
	printList ();
	
	return 0;
}
