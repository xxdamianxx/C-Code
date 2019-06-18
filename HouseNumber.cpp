// This program asks the user to enter a time in the format HH:MM, then interperts the time as being either lucky or just normal.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

int main()
{
	int hours, mins, hr1, hr2, min1, min2;
	char again = 'Y';

	cout << "Let's see what an Amazing Digital Clock can tell you!!!\n";
	cout << "NOTE: Do not enter your numbers without a colon!\n\n";

	while (again == 'y' || again == 'Y') {
		cout << "Enter a time (HH:MM): ";
		string hr_hr, min_min;
		getline(cin, hr_hr, ':');
		getline(cin, min_min, '\n');
		stringstream(hr_hr) >> hours;
		stringstream(min_min) >> mins;

		hr1 = hours / 10;
		hr2 = hours % 10;

		min1 = mins / 10;
		min2 = mins % 10;

		if ((hours < 1 || hours > 12) || (mins < 0 || mins > 59)) {
			cout << "\nError!!!\n";
			cout << "Please use standard time; 1-12 for hour, and 1-59 for minute...\n";
		}

		else if ((hr1 + hr2) == (min1 + min2)) {
			cout << hours << ":" << mins << " is a lucky time.";

			if ((hours == 11 && mins == 11) || (hr1 == 0 && hr2 == min1 && hr2 == min2 && min1 == min2)) {
				cout << "\t-> BINGO! Go buy a lottery ticket. \n";
			}
			else if ((hours == 12 && mins == 34) || (hr1 == 0 && (hr2 == (min1 - 1)) && (min1 == (min2 - 1)))) {
				cout << "\t-> UP! All dreams will come true. \n";
			}
			else if (hr1 == 0 && (hr2 == (min1 + 1)) && (min1 == (min2 + 1))) {
				cout << "\t-> DOWN! Challenging road is ahead. \n";
			}
			else {
				cout << "\n";
			}
		}

		else {
			cout << hours << ":" << min1 << min2 << " is a normal time. ";

			if ((hours == 11 && mins == 11) || (hr1 == 0 && hr2 == min1 && hr2 == min2 && min1 == min2)) {
				cout << "\t-> BINGO! Go buy a lottery ticket. \n";
			}
			else if ((hours == 12 && mins == 34) || (hr1 == 0 && (hr2 == (min1 - 1)) && (min1 == (min2 - 1)))) {
				cout << "\t-> UP! All dreams will come true. \n";
			}
			else if (hr1 == 0 && (hr2 == (min1 + 1)) && (min1 == (min2 + 1))) {
				cout << "\t-> DOWN! Challenging road is ahead. \n";
			}
			else {
				cout << "\n";
			}
		}

		cout << "\nRun program again (y/n)?  ";
		cin >> again;
		cout << "\n\n";
	}

	cout << "Programmer: Pedro Damian Sanchez Jr\n\n";
	cout << "Good bye! Please press the <ENTER> key to exit and have a great day...";

	fflush(stdin);
	cin.get();
	return 0;
}