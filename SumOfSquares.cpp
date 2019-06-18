// This program displayed the sum of the squares and gives the result to the desired 'nth' natural number.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int pattern(int value)
{
	if (value > 0)
		return (value*value) + pattern(value - 1);
	else
		return 0;
}

bool isInteger(string value)
{
	int length = value.length();
	for (int i = 0; i < length; i++)
	{
		if (!isdigit(value[i]))
		{
			return false;
		}
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "The first four numbers in the pattern:\n";
	cout << "Order\t\tNumber\n";
	cout << "  1st\t\t     1\n";
	cout << "  2nd\t\t     5\n";
	cout << "  3rd\t\t    14\n";
	cout << "  4th\t\t    30\n";
	cout << "...\n\n";
	string element;
	int el;
	do
	{
		cout << "What's the ordered element in the pattern that you wanted to find?\n";
		cout << "(Or enter 0 to end): ";
		cin >> element;
		if (isInteger(element))
		{
			el = stoi(element);
			if (el == 0)
			{
				break;
			}
			else
			{

				cout << "The " << el;
				if (element[element.length() - 1] == '1') {
					cout << "st ";
				}
				else if (element[element.length() - 1] == '2')
				{
					cout << "nd ";
				}
				else if (element[element.length() - 1] == '3')
				{
					cout << "rd ";
				}
				else
				{
					cout << "th ";
				}
				cout << "element is: " << pattern(el) << "\n\n";
			}
		}
		while (!isInteger(element))
		{
			cout << "\nYou entered an invalid value. Positive integer was expected.\n";
			cout << "Re-enter ordered element in the pattern that you wanted to find: ";
			cin >> element;
			el = stoi(element);
			if (isInteger(element))
			{
				el = stoi(element);
				if (el == 0)
				{
					break;
				}
				else
				{
					cout << "The " << el;
					if (element[element.length() - 1] == '1') {
						cout << "st ";
					}
					else if (element[element.length() - 1] == '2')
					{
						cout << "nd ";
					}
					else if (element[element.length() - 1] == '3')
					{
						cout << "rd ";
					}
					else
					{
						cout << "th ";
					}
					cout << "element is: " << pattern(el) << "\n\n";
				}
			}
		}
	} while (el != 0);

	cout << "\n\nProgrammer: Pedro Damian Sanchez Jr - CISC 192/C++ Programming.\n";
	cout << "Thanks for using the application, farewell.\n\n";
	cout << "Press <Enter> key to continue...";
	cin.get();
	cin.ignore();
}