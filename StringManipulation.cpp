#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> entries; string input;

	cin >> input;

	while (input != "quit") 
	{
		if (input.length() > 1) 
		{
			entries.push_back(input);
		}
		else if (input.size() == 1)
		{
			for (int i = 0; i < entries.size(); i++)
			{
				if (entries[i][0] == input[0])
				{
					cout << entries[i] << endl;
				}
			}
		}

		cin >> input;

	}

    return 0;
}