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

unsigned countPositiveNumbers (node *head)
{
	unsigned pos = 0;
	node *conductor = head;
	while (conductor->next)
	{
		conductor = conductor->next;
		if (conductor->info >= 0)
			pos++;
	}
	
	return pos;
}

float computeArithmeticMeanOfNegativeNumbers (node *head)
{
	float mean = 0, negative = 0;
	node *conductor = head;
	while (conductor->next)
	{
		conductor = conductor->next;
		if (conductor->info < 0)
		{
			mean += conductor->info;
			negative++;
		}
	}
	mean /= negative;
	
	return mean;
}

int main (int argc, char const *argv[])
{
	node *head = new node;
	head->next = 0;
	
	prepend (head, 64);
	prepend (head, 128);
	prepend (head, -18);
	prepend (head, 256);
	prepend (head, -4);
	prepend (head, -3);
	prepend (head, 2);
	prepend (head, 27);
	
	// printList (head);
	
	cout << countPositiveNumbers (head) << '\n';
	
	cout << computeArithmeticMeanOfNegativeNumbers (head) << '\n';
	
	return 0;
}
