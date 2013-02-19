#include <iostream>
#include <string>
using namespace std;

struct node
{
	int val;
	node *next;
} *inverted;

unsigned aLen, bLen;

void append (node *head, const int &value)
{	
	node *add = new node;
	add->val = value;
	add->next = 0;
	
	if (!head->next) // list is empty
	{
		head->next = add;
		return;
	}
	
	node *conductor = head->next;
	
	while (conductor->next)
	{
		conductor = conductor->next;
	}
	
	conductor->next = add;
}

void printList (node *head)
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
		
		cout << conductor->val;
	}
	cout << '\n';
}

void str_to_list (string &str, node *head)
{
	for (unsigned i = 0; i < str.length (); i++)
	{
		append (head, (int)str[i] - 48);
	}
}

unsigned listLength (node *head)
{
	node *conductor = head;
	unsigned length = 0;
	
	while (conductor->next)
	{
		length++;
		conductor = conductor->next;
	}
	
	return length;
}

unsigned deeper (node *a, node *b)
{
	unsigned sumVal = 0;
 	if (a->next && b->next)
	{
		sumVal += deeper (a->next, b->next);
	}
	
	sumVal += a->val + b->val;
	//cout << a->val << " + " << b->val << " = " << sumVal << '\n';
	
	append (inverted, sumVal % 10);
	
	return (sumVal / 10);
}

void deepAppend (node *nod, node *where)
{
	if (nod->next)
	{
		deepAppend (nod->next, where);
	}
	
	append (where, nod->val);
}

unsigned deeper2 (node *a, node *b)
{
	unsigned sumVal = 0;
	
	unsigned aVal, bVal;
	if (aLen != bLen)
	{
		if (aLen > bLen)
		{
			aLen--;
			sumVal += deeper (a->next, b);
			aVal = a->val;
			bVal = 0;
		}
		else
		{
			bLen--;
			sumVal += deeper (a, b->next);
			aVal = 0;
			bVal = b->val;
		}
	}
	else if (a->next && b->next)
	{
		sumVal += deeper (a->next, b->next);
	}
	
	sumVal += aVal + bVal;
	cout << aVal << " + " << bVal << " = " << sumVal << '\n';
	
	append (inverted, sumVal % 10);
	
	return (sumVal / 10);
}

void addListsRecursively (node *a, node *b, node *sum)
{
	node *aConductor = a->next, *bConductor = b->next, *sumConductor = sum;
	aLen = listLength (a); bLen = listLength (b);
	
	node *prev = new node;
	if (aLen != bLen)
	{
		if (aLen > bLen)
		{
			// offset a, and add to sum
			while (aLen != bLen)
			{
				aLen--;
				prev = sumConductor;
				append (sum, aConductor->val);
				aConductor = aConductor->next;
				sumConductor = sumConductor->next;
			}
		}
		else
		{
			// offset b, and add to sum
			while (aLen != bLen)
			{
				bLen--;
				prev = sumConductor;
				append (sum, bConductor->val);
				bConductor = bConductor->next;
				sumConductor = sumConductor->next;
			}
		}
	}
	
	inverted = new node;
	inverted->next = 0;
	
	if (deeper (aConductor, bConductor))
		sumConductor->val++;
	
	inverted = inverted->next;
	
	deepAppend (inverted, sumConductor);
}

int main (int argc, char const *argv[])
{
	node *oneHead = new node, *twoHead = new node;
	oneHead->next = 0; twoHead->next = 0;
	
	string oneString =	 "328398392839189289";
	string twoString ="383838382821171763161";
	
	str_to_list (oneString, oneHead);
	str_to_list (twoString, twoHead);
	
	node *sumHead = new node; sumHead->next = 0;
	
	addListsRecursively (oneHead, twoHead, sumHead);
	
	cout << "   "; printList (oneHead);
	printList (twoHead);
	printList (sumHead);
	
	return 0;
}
