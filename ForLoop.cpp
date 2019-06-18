// User may write text and have it copied multiple times.

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n; string copy;
	
	getline (cin,copy);
	cin >> n;
  	
	for (int i = 0; i < n; i++)
	{
		cout << copy << endl;
	}

	return 0;
}