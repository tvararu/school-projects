#include <iostream>
using namespace std;

struct node
{
	int info;
	node *next;
	node()
	{
		info = 0;
		next = 0;
	}
};

bool isEmpty (node *stack)
{
	return !stack->next;
}

void push (const int &a, node *stack)
{
	node *conductor = stack;
	while (conductor->next)
	{
		conductor = conductor->next;
	}
	
	node *add = new node;
	add->info = a;
	
	conductor->next = add;
}


void print (node *stack)
{
	node *conductor = stack;
	cout << "Stiva: ";
	while (conductor->next)
	{
		conductor = conductor->next;
		cout << conductor->info << ' ';
	}
	cout << '\n';
}

int pop (node *stack)
{
	if (isEmpty (stack))
		return 0;
	
	node *conductor = stack, *prev = new node;
	while (conductor->next)
	{
		prev = conductor;
		conductor = conductor->next;
	}
	
	int info = conductor->info;
	prev->next = 0;
	delete conductor;
	
	return info;
}

int peek (node *stack)
{
	if (isEmpty (stack))
		return 0;
	
	node *conductor = stack, *prev = new node;
	while (conductor->next)
	{
		prev = conductor;
		conductor = conductor->next;
	}
	
	int info = conductor->info;
	
	return info;
}

int search (const int &a, node *stack)
{
	node *conductor = stack->next;
	int count = 0;
	while (conductor->next)
	{
		if (conductor->info == a)
			return count;
		conductor = conductor->next;
		count++;
	}
	return -1;
}

int main (int argc, char const *argv[])
{
	node *stiva = new node;
	print (stiva);
	
	push (1, stiva);
	push (2, stiva);
	push (3, stiva);
	push (4, stiva);
	print (stiva);
	
	cout << pop (stiva) << endl;
	cout << pop (stiva) << endl;
	print (stiva);
	
	cout << peek (stiva) << endl;
	print (stiva);
	
	cout << isEmpty (stiva) << endl;
	pop (stiva);
	pop (stiva);
	cout << isEmpty (stiva) << endl;
	
	push (1, stiva);
	push (2, stiva);
	push (3, stiva);
	push (4, stiva);
	print (stiva);
	
	cout << search (3, stiva) << endl;
	cout << search (-3, stiva) << endl;
	
	return 0;
}
