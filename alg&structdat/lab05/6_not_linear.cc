#include <iostream>
#include <string>
using namespace std;

int main (int argc, char const *argv[])
{
	string w = "abcdef abcdef";
	string margine;
	for (unsigned i = 1, j = w.length() - 1; i < w.length() && j >= 0; i++, j--)
	{
		string begin(w.begin(), w.begin() + i);
		string end(w.begin() + j, w.end());
		cout << begin << " | " << end << '\n';
		if (begin == end)
			margine = begin;
	}
	
	cout << margine << endl;
	
	return 0;
}
