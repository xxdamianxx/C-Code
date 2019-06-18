#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// Create an empty vector
	vector<string> names;

	// This does not work because vector is empty
	// names[0] = "Joe";

	// Create a vector of 5 elements
	vector<string> names2 = vector<string>(5);

	cout << names.capacity() << endl;  //0
	cout << names2.capacity() << endl; //5

	names2[0] = "Joe";
	names2[1] = "Jill";

	names.push_back("Joe");
	names.push_back("Jill");
	names.push_back("Jack");
	names.push_back("Jane");
	names.push_back("John");

	cout << names2.size() << endl;
	cout << names2.capacity() << endl;

	cout << names.empty() << endl;

	for (int i = 0; i < names.size(); i++)
	{
		cout << names[i] << endl;
	}

	fflush(stdin);
	cin.get();

	return 0;
}

