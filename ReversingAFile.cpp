#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> buf;
	ifstream in("code.cpp");

	while (in)
	{
		string s;
		getline(in, s);
		if (in) buf.push_back(s);
	}

	int line = 0;

	for (int i = buf.size()-1; i >= 0; i--)
	{
		cout << line << ": " << buf[i] << endl;
		line++;
	}

    return 0;
}