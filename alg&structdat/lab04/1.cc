#include <iostream>
using namespace std;
#define MULT 100

int top = 0;

void push (const int &a, int *stiva)
{
	stiva[top] = a;
	top++;
}

bool isEmpty (int *stiva)
{
	return !top;
}

int pop (int *stiva)
{
	if (isEmpty(stiva))
		return -1;
	
	return stiva[--top];
}

int peek (int *stiva)
{
	if (isEmpty(stiva))
		return -1;
	
	return stiva[top - 1];
}

int search (const int &a, int *stiva)
{
	for (int i = 0; i < top; i++)
	{
		if (stiva[i] == a)
			return i + 1;
	}
	
	return -1;
}

void print (int *stiva)
{
	for (int i = 0; i < top; i++)
	{
		cout << stiva[i] << ' ';
	}
	cout << endl;
}

int main (int argc, char const *argv[])
{
	int stiva[MULT];
	
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
