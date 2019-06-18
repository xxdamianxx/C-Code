// Calculating the volume of a swimming pool.

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << fixed << showpoint << setprecision(2);

	double length, width, depth, volume, water, cost;

	cout << "Please enter the dimensions of the pool you want built, and our automated" << endl << "program will perform the calculations of the size of the pool," << endl << "the water needed, and, the cost of the water required." << endl;
	cout << endl;

	cout << "Enter length (in feet):" << endl;
	cin >> length;

	cout << endl;

	cout << "Enter width (in feet):" << endl;
	cin >> width;

	cout << endl;

	cout << "Enter depth (in feet):" << endl;
	cin >> depth;

	cout << endl;

	cout << "***Invoice*** September 7, 2016" << endl;

	cout << endl;

	volume = length * width * depth;

	cout << "The volume of the pool shall be:" << endl;

	cout << volume << " ""cubic feet" << endl;

	cout << endl;

	water = volume - (length * width * 0.25);

	cout << "The amount of water needed is:" << endl;

	cout << water << " ""cubic feet" << endl;

	cout << endl;

	if (water > 0)
	{
		cost = (water*0.77) + 100;
		cout << "The cost comes out to:" << endl;
		cout << cost << " " "U.S. Dollars" << endl;
	}
	else if (water < 1)
	{
		cost = 0;
		cout << "None";
	}

	cout << endl;

	cout << "Thank you for chooing Smarter Homes INC. for your pool designs," << endl << "please press the <Enter> key to proceed." << endl;

	cout << endl;

	cout << "Programmed by: Pedro Damian Sanchez Jr" << endl;

	cout << endl;

	fflush(stdin);
	cin.get();

	return 0;
}