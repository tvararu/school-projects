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

void append (node *head, const int &value)
{
	if (!head->next) // list is empty
	{
		prepend (head, value);
		return;
	}
	
	node *conductor = head->next;
	
	while (conductor->next)
	{
		conductor = conductor->next;
	}
	
	node *add = new node;
	add->info = value;
	add->next = 0;
	
	conductor->next = add;
}

node* reverse_1 ()
{
	static node *headReverse = new node;
	return headReverse;
}

void reverse (node *head)
{
	if (head->next)
	{
		reverse (head->next);
	}
	append (reverse_1(), head->info);
}

void reverseList (node *ogHead, node *head, node *prev, int count, const int &length)
{
	if (head->next)
	{
		prev = head;
		head = head->next;
		reverseList (ogHead, head, prev, count + 1, length);
	}
	if (count + 1 == length)
	{
		// cout << "We're at the end, so I'll just rewrite the original head to " << head->info << '\n';
		ogHead->next = head;
	}
	head->next = prev; // cout << "Rewrote " << head->info << "->next to " << prev->info << '\n';
	prev->next = 0; // cout << "Rewrote " << prev->info << "->next to nothing\n";
	
	// cout << "We're about to go down a recursion step, and the list is looking like this:\n";
	// printList (ogHead);
}

int calcLength (node *head)
{
	int length = 0;
	node *conductor = head;
	while (conductor->next)
	{
		conductor = conductor->next;
		length++;
	}
	
	return length;
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
	
	cout << "subpunctul a.\n";
	printList (head);
	reverse (head->next);
	printList (reverse_1());
	
	cout << "\nsubpunctul b.\n";
	printList (head);
	reverseList (head, head->next, head, 0, calcLength (head));
	printList (head);
	
	return 0;
}
