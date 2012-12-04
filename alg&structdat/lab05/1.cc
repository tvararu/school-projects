#include <iostream>
using namespace std;

struct node
{
	int val;
	node *next;
	node *prev;
	node()
	{
		val = 0;
		next = 0;
		prev = 0;
	}
};

bool is_empty (node *head)
{
	return !head->next;
}

void push_back (node *head, const int &a)
{
	node *conductor = head;
	while (conductor->next)
	{
		conductor = conductor->next;
	}
	
	node *push = new node;
	push->val = a;
	push->prev = conductor;
	conductor->next = push;
}

void push_front (node *head, const int &a)
{
	if (is_empty (head))
	{
		push_back (head, a);
		return;
	}
	
	node *first = head->next;
	
	node *push = new node;
	push->val = a;
	
	first->prev = push;
	head->next = push;
	push->prev = head;
	push->next = first;
}

void print (node *head)
{
	node *conductor = head;
	while (conductor->next)
	{
		conductor = conductor->next;
		cout << conductor->val << ' ';
	}
	cout << '\n';
}

void print_reverse (node *head)
{
	node *conductor = head;
	while (conductor->next)
	{
		conductor = conductor->next;
	}
	
	while (conductor->prev)
	{
		cout << conductor->val << ' ';
		conductor = conductor->prev;
	}
	cout << '\n';
}

void push_pos (node *head, const int &a, int pos)
{
	node *conductor = head;
	while (conductor->next && --pos)
	{
		conductor = conductor->next;
	}
	
	node *push = new node;
	push->val = a;
	(conductor->next)->prev = push;
	push->next = conductor->next;
	conductor->next = push;
	push->prev = conductor;
}

void pop_pos (node *head, int pos)
{
	node *conductor = head;
	while (conductor->next && pos--)
	{
		conductor = conductor->next;
	}
	
	node *target = conductor;
	(target->next)->prev = target->prev;
	(target->prev)->next = target->next;
	delete target;
}

void pop_val (node *head, const int &val)
{
	node *conductor = head;
	while (conductor->next && conductor->val != val)
	{
		conductor = conductor->next;
	}
	
	node *target = conductor;
	(target->next)->prev = target->prev;
	(target->prev)->next = target->next;
	delete target;
}

int main (int argc, char const *argv[])
{
	node *head = new node;
	
	push_front(head, 99);
	push_front(head, 4);
	push_front(head, 5);
	push_back(head, 6);
	
	print(head);
	print_reverse(head);
	
	push_pos (head, 13, 2);
	print(head);
	
	pop_pos (head, 3);
	
	print(head);
	
	pop_val (head, 99);
	
	print(head);
	
	return 0;
}
