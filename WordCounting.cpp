// This program takes a text file and counts the number of whitespaces in the text.

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	ifstream ifs("words.txt");
	int words = 0;
	string word;

	while (ifs >> word)
	{
		++words;
	}
	
	cout << words << endl;

    return 0;
}