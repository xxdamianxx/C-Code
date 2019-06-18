#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string buf;
	ifstream in("code.cpp");

	while (in)
	{
		string s;
		getline(in, s);
		if (in) buf += s;
	}

	cout << buf << endl;

	return 0;
}