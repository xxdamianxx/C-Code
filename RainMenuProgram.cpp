// This is a C++ menu-driven program that allows the user do two operations, t can make an open box with largest possible volume, 
// and, It reads rainfall values for each of 12 months in a year, from an external text file starting with January and ending with December.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
	cout << fixed << showpoint << setprecision(2);

	int choice;
	double width, length;
	char again = 'Y';
	ifstream inFile;
	string data, filename;

	while (again == 'y' || again == 'Y')
	{
		do
		{
			system("cls");
			cout << "" << endl;
			cout << "                                   MAIN MENU" << endl;
			cout << "                             *^*^*^*^*^*^*^*^*^*^" << endl;
			cout << endl;
			cout << "                           1: Optimaztion of Box" << endl;
			cout << "                           2: Rainfall Statistics" << endl;
			cout << "                           3: End Program" << endl;
			cout << endl;

			cout << "Enter your choice: ";
			cin >> choice;
			cout << endl;

			if (choice == 1)
			{
				cout << endl;
				cout << endl;
				cout << "Let's make an open box..." << endl;
				cout << endl;

				cout << "Enter the width: ";
				cin >> width;
				cout << endl;

				cout << "Enter the length: ";
				cin >> length;
				cout << endl;
				cout << endl;

				cout << endl;
				cout << "Here are the Box's properties..." << endl;
				cout << endl;

				double DA, DS, VA, VS;
				double a, b, c;
				double cutsize, volume;
				a = 12.0f;
				b = -(4 * length + 4 * width);
				c = width*length;
				DA = ((-(b)+sqrt((pow(b, 2)) - (4 * a*c))) / (2 * a));
				DS = ((-(b)-sqrt((pow(b, 2)) - (4 * a*c))) / (2 * a));
				VA = DA * (width - (2 * DA)) * (length - (2 * DA));
				VS = DS * (width - (2 * DS)) * (length - (2 * DS));

				cout << "With a length of: " << length << endl;
				cout << "And a width of: " << width << endl;
				cout << endl;

				if (VA > VS)
				{
					cutsize = DA;
					volume = VA;
				}
				else
				{
					cutsize = DS;
					volume = VS;
				}
				cout << "The maximum volume: " << volume << endl;
				cout << "The size of the cut: " << cutsize << endl;
				cout << endl;

				cout << "Press <Enter> key to continue ...";
				cin.ignore();
				cin.get();
			}
			else if (choice == 2)
			{
				cout << "The programs reads rainfall value for each of 12 months in a year." << endl;
				cout << "from an external text file starting with January and ending with December," << endl;

				do
				{
					cout << "Enter the filename for rainfall data (or -1 to quit): ";
					cin >> filename;

					inFile.open(filename);

					double rain[12];
					double largest = 0;
					double smallest = 0;
					double total = 0;
					double firstRain;
					int smallMonthNo = 0;
					int largeMonthNo = 0;
					string month[12] = { "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

					if (!inFile)
					{
						cout << "The file could not be opened" << endl;
					}
					else
					{
						filename = "-1";
						inFile >> firstRain;
						smallest = firstRain;
						largest = firstRain;
						rain[0] = firstRain;
						//cout << firstRain << "\n";
						for (int i = 1; i <= 11; i++)
						{
							inFile >> rain[i];

							if (rain[i] > largest)
							{
								largest = rain[i];
								largeMonthNo = i;
							}

							if (rain[i] < smallest)
							{
								smallest = rain[i];
								smallMonthNo = i;
							}

							total += rain[i];
							//cout << rain[i] << '\n';
						}

						total += firstRain;
					}

					cout << "The total : " << total << " inches." << endl;
					cout << "The average : " << total / 12.0 << " inches." << endl;
					cout << "The largest : " << largest << " inches in " << month[largeMonthNo] << endl;
					cout << "The smallest : " << smallest << " inches in " << month[smallMonthNo] << endl;
					cout << "Month\t\tRainfall" << endl;
					cout << "=====\t\t========" << endl;
					
					for (int i = 0; i <= 11; i++)
					{
						cout << left << month[i] << right << rain[i];
						
						if (i == largeMonthNo)
						{
							cout << "(largest)" << endl;
						}

						if (i == smallMonthNo)
						{
							cout << "(smallest)" << endl;
						}
						
						if (i != smallMonthNo && i != largeMonthNo)
						{
							cout << endl;
						}
					}

					inFile.close();
					cin.ignore();
					cin.get();

				}while (filename != "-1");
			}
			else if (choice == 3)
			{
				cout << "Programmed by: Pedro Damian Sanchez Jr" << endl;
				cout << endl;
				cout << "BYE BYE!!! Press <Enter> key to END the program...";
				cout << endl;
			}
			else
			{
				cin.clear();
				cin.ignore(100, '\n');

				cout << "ERROR!!!" << endl;
				cout << "Re-Enter your choice: ";
				cin >> choice;
				//system("cls");
			}
		} while (choice != 3);
	}

	if (!(again == 'y' || again == 'Y'))
	{
		cout << endl;

		cout << "Programmed by: Pedro Damian Sanchez Jr" << endl;

		cout << endl;

		cout << "Please press the <ENTER> key to exit and have a good day.";
	}

	cout << endl;

	fflush(stdin);
	cin.get();

	return 0;
}