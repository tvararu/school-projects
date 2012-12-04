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
} *back;

bool isEmpty (node *queue)
{
	return !queue->next;
}

void push (const int &a, node *queue)
{
	node *add = new node;
	add->info = a;
	
	back->next = add;
	back = add;
}


void print (node *queue)
{
	node *conductor = queue;
	cout << "Coada: ";
	while (conductor->next)
	{
		conductor = conductor->next;
		cout << conductor->info << ' ';
	}
	cout << '\n';
}

int pop (node *queue)
{
	if (isEmpty (queue))
		return 0;
	
	int info = queue->next->info;
	queue->next = queue->next->next;
	delete queue->next;
	
	if (isEmpty (queue))
		back = queue;
	
	return info;
}

int peek (node *queue)
{
	if (isEmpty (queue))
		return 0;
	
	return queue->next->info;
}

int search (const int &a, node *queue)
{
	node *conductor = queue->next;
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
	node *coada = new node;
	back = coada;
	print (coada);
	
	push (1, coada);
	push (2, coada);
	push (3, coada);
	push (4, coada);
	print (coada);
	
	cout << pop (coada) << endl;
	cout << pop (coada) << endl;
	print (coada);
	
	cout << peek (coada) << endl;
	print (coada);
	
	cout << isEmpty (coada) << endl;
	pop (coada);
	pop (coada);
	cout << isEmpty (coada) << endl;
	
	push (1, coada);
	push (2, coada);
	push (3, coada);
	push (4, coada);
	print (coada);
	
	cout << search (3, coada) << endl;
	cout << search (-3, coada) << endl;
	
	return 0;
}
