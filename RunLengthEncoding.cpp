#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n; char c; string input;
	
	while (true)
	{
		cin >> c;
  		cin >> n;

		if (n == -2)
		{
			break;
		}
		else if (n == -1)
		{
			cout << endl;
		}
		else
		{
			for (int i = n; i > 0; i--)
			{
				cout << c;
			}
		}
	}

	return 0;
}