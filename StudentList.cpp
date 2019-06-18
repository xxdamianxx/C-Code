// This program determines the placement of the two students in the front and back of the line by alphebetical order.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	ofstream outFile;
	ifstream inFile;

	outFile.open("Student.txt");
	inFile.open("Student.txt");

	int numStudents = 0;

	string studentName, firstStudent, lastStudent;
	char again = 'Y';

	while (again == 'y' || again == 'Y')
	{
		cout << "This program determines the placement of the two students" << endl << "(in a classroom sized from 5 to 30 students) in the front and back" << endl << "of a single file line based on the alphebetical order of their first names." << endl;
		cout << endl;

		cout << "Please enter number of students in the class:" << endl;
		cin >> numStudents;
		cout << endl;

		while (numStudents < 5 || numStudents > 30)
		{
			cin.clear();
			cin.ignore(100, '\n');

			cout << "ERROR!!! INVALID ENTRY!" << endl << "The number of students in the class must range from 5 to 30 total." << endl << endl << "Please enter a number between 5 and 30:" << endl;
			cin >> numStudents;

			cout << endl;
		}

			for (int i = 1; i <= numStudents; i++)
			{
				cout << "Please enter name of student #" << i << endl;
				cin >> studentName;
				cout << endl;

				if (i == 1)
				{
					firstStudent = studentName;
					lastStudent = studentName;
				}
				else
				{
					if (studentName < firstStudent)
					{
						firstStudent = studentName;
					}
					else if (studentName > lastStudent)
					{
						lastStudent = studentName;
					}
				}
			}
		cout << endl;

		cout << "	The student who is first in line is " << firstStudent << "." << endl;
		cout << endl;

		cout << "	The student who is last in line is " << lastStudent << "." << endl;
		cout << endl;

		getline(cin, studentName, '\n');

		getline(inFile, studentName, '\n');

		cout << endl;

		cout << "Would you like the rerun this program (y/n)?  ";

		cin >> again;

		cout << endl;

		cout << endl;

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