#include <iostream>
#include <stack>
#include <string>
using namespace std;

// trebuie stiva manuala

int main (int argc, char const *argv[])
{
	stack<char> stiva;
	
	string sir = "12213344";
	
	for (unsigned i = 0; i < sir.length(); i++)
	{
		if (!stiva.size())
		{
			stiva.push(sir[i]);
			continue;
		}
		
		if (stiva.top() != sir[i])
			stiva.push(sir[i]);
		else
			stiva.pop();
	}
	
	cout << "Configuratia este " << (stiva.size() ? "invalida" : "valida");
	
	return 0;
}
