#include <iostream>
#include <stack>
#include <string>
using namespace std;

// trebuie stiva manuala

int main (int argc, char const *argv[])
{
	stack<char> stiva;
	
	string sir = "()(((((((()))(";
	
	for (unsigned i = 0; i < sir.length(); i++)
	{
		if (!stiva.size())
		{
			if (sir[i] == ')')
			{
				cout << "Parantezare incorecta la pozitia " << i << endl;
				exit(0);
			}
			stiva.push(sir[i]);
			continue;
		}
		
		if (stiva.top() == sir[i])
			stiva.push(sir[i]);
		else
			stiva.pop();
	}
	
	cout << "Parantezare " << ((stiva.size() && stiva.top() != '(')  ? "incorecta" : "corecta");
	
	return 0;
}
