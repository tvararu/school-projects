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

void split (node *head3, node *head1, node *head2)
{
	node *cond3 = head3->next, *cond1 = head1, *cond2 = head2;
	
	bool tick = false;
	while (cond3->next)
	{
		if (tick)
		{
			tick = false;
			cond2->next = cond3;
			cond2 = cond2->next;
		}
		else
		{
			tick = true;
			cond1->next = cond3;
			cond1 = cond1->next;
		}
		cond3 = cond3->next;
	}
	if (tick)
	{
		cond2->next = cond3;
		cond2 = cond2->next;
	}
	else
	{
		cond1->next = cond3;
		cond1 = cond2->next;
	}
	cond2->next = 0;
	cond1->next = 0;
}

int main (int argc, char const *argv[])
{
	node *L1 = new node, *L2 = new node, *L3 = new node;
	L1->next = 0;
	L2->next = 0;
	L3->next = 0;
	
	for (int i = 10; i > 0; i--)
		prepend (L3, i);
	
	printList (L3);
	
	split (L3, L1, L2);
	
	printList (L1);
	printList (L2);
	
	return 0;
}
