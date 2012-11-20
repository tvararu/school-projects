#include <iostream>
#include <string>
using namespace std;

int main (int argc, char const *argv[])
{
	string w = "abcxabcabc";
	string margine;
	unsigned begin = 0, runner = 0;
	while (++runner < w.length())
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
					break;
				}
			}
			if (match)
			{
				string found (w.begin(), w.begin() + (w.length() - from));
				margine = found;
			}
		}
	}
	
	cout << margine << endl;
	
	return 0;
}
