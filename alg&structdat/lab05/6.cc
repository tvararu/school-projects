#include <iostream>
#include <string>
using namespace std;

int main (int argc, char const *argv[])
{
	string w = "ababa";
	string margine;
	unsigned begin = 0, runner = 1;
	while (runner < w.length())
	{
		if (w[begin] == w[runner])
		{
			// found possible match, see if it lasts until the end of the string
			int from = runner;
			bool match = true;
			while (runner < w.length())
			{
				if (w[begin++] != w[runner++])
				{
					match = false;
					begin = 0;
					runner -= 2;
					break;
				}
			}
			if (match)
			{
				string found (w.begin(), w.begin() + (w.length() - from));
				margine = found;
			}
		}
		runner++;
	}
	
	if (margine.length ())
		cout << margine << endl;
	else
		cout << "Nu exista margine.\n";
	
	return 0;
}
