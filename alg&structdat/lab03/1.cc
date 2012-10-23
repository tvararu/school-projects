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

void insertionSort (node *head)
{
	node *conductor = head->next, *prev = new node;
	while (conductor->next)
	{
		prev = conductor;
		conductor = conductor->next;
		if (prev->info > conductor->info)
		{
			node *cond2 = head->next, *prev2 = head;
			while (cond2->next)
			{
				if (cond2->info > conductor->info)
				{
					prev->next = conductor->next;
					prev2->next = conductor;
					conductor->next = cond2;
					conductor = prev;
					break;
				}
				prev2 = cond2;
				cond2 = cond2->next;
			}
		}
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
	
	insertionSort (head);
	
	printList (head);
	
	return 0;
}
