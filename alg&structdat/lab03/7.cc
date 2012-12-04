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

void combine (node *list1, node *list2, node *list3)
{
	node *cond1 = list1->next, *cond2 = list2->next, *cond3 = list3;
	
	while (cond1->next || cond2->next)
	{
		if (cond1->info < cond2->info)
		{
			cond3->next = cond1;
			cond1 = cond1->next;
		}
		else
		{
			cond3->next = cond2;
			cond2 = cond2->next;
		}
		
		cond3 = cond3->next;
	}
	// off by one
	if (cond1->info < cond2->info)
	{
		cond3->next = cond1;
		cond1 = cond1->next;
	}
	else
	{
		cond3->next = cond2;
		cond2 = cond2->next;
	}
	
	cond3 = cond3->next;
}

int main (int argc, char const *argv[])
{
	node *L1 = new node, *L2 = new node, *L3 = new node;
	L1->next = 0;
	L2->next = 0;
	L3->next = 0;
	
	prepend (L1, 12);
	prepend (L1, 9);
	prepend (L1, 8);
	prepend (L1, 7);
	prepend (L1, 4);
	prepend (L1, 1);
	
	printList (L1);
	
	prepend (L2, 10);
	prepend (L2, 6);
	prepend (L2, 5);
	prepend (L2, 3);
	prepend (L2, 2);
	prepend (L2, 0);
	
	printList (L2);
	
	combine (L1, L2, L3);
	
	printList (L3);
	
	return 0;
}
