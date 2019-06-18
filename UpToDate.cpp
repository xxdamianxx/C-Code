// This program is a date formating software that converts a numerical calendar day such as 12/25/2012 (US) into
// December 25, 2012 (US expanded)
// 25 December 2012 (US Military)
// 2012 - 12 - 25 (International)

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;

public:
	Date();
	Date(int, int, int);
	~Date() {};
	bool isMonth(int);
	bool isDay(int, int);
	bool isYear(int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void printUSDate();
	void printUSExpandedDate();
	void printUSMilitaryDate();
	void printInternational();

};

Date::Date()
{
	month = 0;
	day = 0;
	year = 0;
}

Date::Date(int Month, int Day, int Year)
{
	month = Month;
	day = Day;
	year = Year;
}

void Date::setMonth(int m)
{
	month = m;
}

bool Date::isMonth(int m)
{
	if (m > 12 || m < 1)
	{
		cout << endl;
		cout << m << " is not a valid month\n";
		return false;
	}
	else
	{
		return true;
	}
}

void Date::setDay(int d)
{
	day = d;
}

void Date::setYear(int y)
{
	year = y;
}

bool Date::isYear(int y)
{
	if ((y % 4 == 0) && !(y % 100 == 0) || (y % 400 == 0))
	{
		cout << endl;
		cout << y << " is a leap year.\n";
		return true;
	}
	else
	{
		cout << endl;
		cout << y << " is not a leap year.\n";
		return true;
	}
}

bool Date::isDay(int d, int m)
{
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (d > 31 || d < 1)
		{
			cout << endl;
			cout << "ERROR!!! " << d << " is not a day valid in the month of " << months[m - 1] << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (m == 2)
	{
		if (d > 28 || d < 1)
		{
			cout << endl;
			cout << "ERROR!!! " << d << " is not a day valid in the month of " << months[m - 1] << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		if (d > 30 || d < 1)
		{
			cout << endl;
			cout << "ERROR!!! " << d << " is not a day valid in the month of " << months[m - 1] << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
}

void Date::printUSDate()
{
	cout << month << "/" << day << "/" << year << " (US).\n";
}

void Date::printUSExpandedDate()
{
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	cout << months[month - 1] << " " << day << ", " << year << " (US Expanded).\n";
}

void Date::printUSMilitaryDate()
{
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	cout << day << " " << months[month - 1] << " " << year << " (US Military).\n";
}

void Date::printInternational()
{
	cout << year << "-" << month << "-" << day << " (International).\n";
}

int main()
{
	string date;
	char choice;
	int month, day, year;
	Date dateFormat;

	do
	{
		cout << "The program displays a valid date in three different formats.\n";
		cout << "Note: All junk data will be rejected!\n";
		cout << endl;
		cout << "Enter a date(mm/dd/yyyy) or -1 to end: ";
		cin >> date;


		if (date == "-1")
		{
			cout << endl;
			cout << "Programmed by: Pedro Damian Sanchez Jr\n";
			cout << "Good bye! Please press the <Enter> key to end the program...\n";

			fflush(stdin);
			cin.get();

			return 0;
		}
		else
		{
			if (date.length() == 10)
			{
				month = stoi(date.substr(0, 2));
				day = stoi(date.substr(3, 2));
				year = stoi(date.substr(6));

				if (dateFormat.isMonth(month) && dateFormat.isYear(year) && dateFormat.isDay(day, month))
				{
					Date dateFormat = Date(month, day, year);
					cout << "\nDate: " << month << "/" << day << "/" << year << " is valid\n\n";
					dateFormat.printUSDate();
					dateFormat.printUSExpandedDate();
					dateFormat.printUSMilitaryDate();
					dateFormat.printInternational();
					cout << endl;
					cout << "Run again (y / n)? ";
					cin >> choice;
					cout << endl;
					cout << endl;
					if (choice != 'y' && choice != 'Y')
					{
						break;
					}
				}
				else
				{
					cout << "Error!!! The entered date is invalid! Re-Enter, Please!\n\n";
					choice = 'Y';
				}
			}
			else
			{
				cout << "\nInvalid date/wrong format!\n";
				cout << "For both month and day use two digits, and, for year use four digits...\n\n";
				choice = 'Y';
			}
		}
	} while (choice != 'y' || choice != 'Y');

	cout << endl;
	cout << "Programmed by: Pedro Damian Sanchez Jr\n";
	cout << "Good bye! Please press the <Enter> key to end the program...\n";

	fflush(stdin);
	cin.get();
	
	return 0;
}