#include <iostream>
using namespace std;

struct node
{
	int val;
	node *next;
} *head;

void insertElement (const int &value)
{
	node *conductor = head;
	
	while (conductor->next)
	{
		conductor = conductor->next;
	}
	
	node *add = new node;
	add->val = value;
	add->next = 0;
	
	conductor->next = add;
}

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

void removeElement (const int &value)
{
	node *conductor = head, *prev;
	
	if (conductor->val == value) // if the target node is the first one
	{
		head = conductor->next;
		
		delete conductor;
		return;
	}
	
	while (conductor->next)
	{
		prev = conductor;
		conductor = conductor->next;
		
		if (conductor->val == value)
		{
			prev->next = conductor->next;
			
			delete conductor;
			return;
		}
	}
	
	if (conductor->val == value)
	{
		prev->next = conductor->next;
		
		delete conductor;
		return;
	}
}

int findElement (const int &value)
{
	node *conductor = head;
	int pos = 0;
	
	while (conductor->next)
	{
		conductor = conductor->next;
		
		if (conductor->val == value)
		{
			return pos;
		}
		
		pos++;
	}
	
	return -1;
}

void empty ()
{
	head->next = 0;
}

int main (int argc, char const *argv[])
{
	head = new node;
	head->next = 0;
	
	insertElement (20);
	insertElement (22);
	insertElement (15);
	insertElement (25);
	
	printList ();
	
	removeElement (22);
	
	printList ();
	
	removeElement (25);
	
	printList ();
	
	cout << "Pozitia lui 15: " << findElement (15) << '\n';
	
	empty ();
	
	printList ();
	
	insertElement (12);
	
	printList ();
	
	return 0;
}
