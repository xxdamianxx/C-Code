// This proram is a Body Mass Index calculator owned by VENUS BODY CONTURING SERVICES INC.

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	cout << fixed << showpoint << setprecision(2);

	double x, weight, height, BMI, idealWeight, adjustedWeight;
	char again = 'y';

	while (again == 'y')
	{
		cout << "Welcome to VENUS BODY CONTURING SERVICES INC." << endl;

		cout << endl;

		cout << "This program will determine your overall Body Mass Index (BMI), fitness status," << endl << "and calculate any necessary weight adjustments required to maintain" << endl << "optimal sexual performance." << endl;
		cout << endl;

		cout << "Please enter your weight (in pounds):" << endl;
		cin >> weight;

		cout << endl;

		cout << "Please enter your height (in inches):" << endl;
		cin >> height;

		cout << endl;

		BMI = (weight * 703) / (height * height);

		if (BMI < 18.5)
		{
			cout << "Your BMI count comes out to:" << endl;
			cout << BMI << endl;

			cout << endl;

			cout << "You are underweight!" << endl;

			cout << endl;

			x = 18.5;
			idealWeight = (x * height * height) / 703;
			adjustedWeight = abs(idealWeight - weight);

			cout << "To stay healthy, you must gain:" << endl;
			cout << "+" << adjustedWeight << " " "pounds" << endl;
		}
		else if (BMI >= 18.5 && BMI < 25.01)
		{
			cout << "Your BMI count comes out to:" << endl;
			cout << BMI << endl;

			cout << endl;
			cout << "You are at normal body weight." << endl;
		}
		else if (BMI >= 25.01 && BMI < 30.01)
		{
			cout << "Your BMI count comes out to:" << endl;
			cout << BMI << endl;

			cout << endl;

			cout << "You are overweight!" << endl;

			cout << endl;

			x = 25.0;
			idealWeight = (x * height * height) / 703;
			adjustedWeight = abs(idealWeight - weight);

			cout << "To stay healthy, you must lose:" << endl;
			cout << "-" << adjustedWeight << " " "pounds" << endl;
		}
		else if (BMI > 30.01)
		{
			cout << "Your BMI count comes out to:" << endl;
			cout << BMI << endl;

			cout << endl;
			cout << "You are obese!" << endl;

			cout << endl;

			x = 25.0;
			idealWeight = (x * height * height) / 703;
			adjustedWeight = abs(idealWeight - weight);

			cout << "To stay healthy, you must lose:" << endl;
			cout << "-" << adjustedWeight << " " "pounds" << endl;
		}

		cout << endl;

		cout << "***DISCLAIMER*** " << endl;

		cout << endl;

		cout << "These BMI values are provided by the," << endl << "Department of Health and Human Services/National Institues of Health." << endl;

		cout << endl;

		cout << "Underwieght:" << "  " "less that 18.5" << endl;
		cout << "Normal:" << "       " "in the interval [18.5 , 25.0]" << endl;
		cout << "Overweight:" << "   " "in the interval (25.0 , 30.0]" << endl;
		cout << "Obese:" << "        " "greater than 30.0" << endl;

		cout << endl;

		cout << endl;

		cout << "Programmed by: Pedro Damian Sanchez Jr" << endl;

		cout << endl;

		cout << endl;

		cout << "Do you want to continue (y/n)?";

		cout << endl;

		cin >> again;

		cout << endl;
	}

	cout << endl;

	fflush(stdin);
	cin.get();

	return 0;
}