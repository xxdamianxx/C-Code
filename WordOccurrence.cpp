#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream ifs("words.txt");
	
	int count = 0;

	string word, any, print;

	cin >> word;

	for (int i = 0; i < word.length(); i++)
	{
		word[i] = toupper(word[i]);
	}

	while (ifs >> any)
	{
		if (word.length() != any.length())
		{
			any.erase(any.length()-1);
		}
		for (int i = 0; i < any.length(); i++)
		{
			any[i] = toupper(any[i]);
		}
		if (word == any)
		{
			count++;
		}
	}

	cout << count << endl;

	return 0;
}