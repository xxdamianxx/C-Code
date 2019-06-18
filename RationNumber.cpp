// This program takes two rational numbers and performs four different arithmetic operations using those two numbers.
//

#include "stdafx.h"
#ifndef RATIONAL_H
#define RATIONAL_H

using namespace std;

class Rational
{
public:
	Rational(int = 0, int = 1);
	Rational addition(const Rational &);
	Rational subtraction(const Rational &);
	Rational multiplication(const Rational &);
	Rational division(const Rational &);
	void printRational();
	void printRationalAsDouble();
private:
	int numerator;
	int denominator;
	void reduction();
};

#endif

#include <iostream>
using namespace std;

Rational::Rational(int num, int denom)
{
	numerator = num;
	denominator = denom;
	reduction();
}

Rational Rational::addition(const Rational &a)
{
	Rational t;
	t.numerator = a.numerator * denominator;
	t.numerator += a.denominator * numerator;
	t.denominator = a.denominator * denominator;
	t.reduction();
	return t;
}

Rational Rational::subtraction(const Rational &s)
{
	Rational t;
	t.numerator = s.denominator * numerator;
	t.numerator -= denominator * s.numerator;
	t.denominator = s.denominator * denominator;
	t.reduction();
	return t;
}


Rational Rational::multiplication(const Rational &m)
{
	Rational t;
	t.numerator = m.numerator * numerator;
	t.denominator = m.denominator * denominator;
	t.reduction();
	return t;
}

Rational Rational::division(const Rational &d)
{
	Rational t;
	t.numerator = d.denominator * numerator;
	t.denominator = denominator * d.numerator;
	t.reduction();
	return t;
}

void Rational::printRational()
{
	if (denominator == 0)
	{
		cout << "\nDivide by zero error\n";
	}
	else if (numerator == 0)
	{
		cout << 0;
	}
	else
	{
		cout << numerator << '/' << denominator;
	}
}

void Rational::reduction()
{
	int largest;
	largest = numerator > denominator ? numerator : denominator;
	int gcd = 0;

	for (int i = 2; i <= largest; i++)
	{
		if (numerator % i == 0 && denominator % i == 0)
		{
			gcd = i;
		}
	}

	if (gcd != 0)
	{
		numerator /= gcd;
		denominator /= gcd;
	}
}

void Rational::printRationalAsDouble()
{
	cout << static_cast<double>(numerator) / denominator;
}

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
	char number[256];
	char choice;
	bool isRational = false;
	int numerator = 0;
	int denominator = 1;
	int length = 0;
	string num;
	int counter = 0;
	bool isValid = false;
	int pos = 0;

	do {
		Rational a, b, c;
		cout << "The program performs arithmetic operations on two rational numbers.\n";
		cout << "\nEnter a rational number (a/b): ";

		while (!isValid)
		{
			cin >> number;
			length = strlen(number);

			for (int i = 0; i < length; i++)
			{
				if (isdigit(number[i]) || number[i] == '/')
				{
					isRational = true;
				}
				else
				{
					cout << "Only digits are allowed! Please!\n";
					isRational = false;
				}
			}

			if (isRational)
			{
				num = number;
				pos = num.find('/');
				cout << pos << "\n";

				if (pos == -1) {
					numerator = stoi(number);
					a = Rational(numerator, 1);
				}
				else
				{
					numerator = stoi(num.substr(0, pos));
					denominator = stoi(num.substr(pos + 1));
					a = Rational(numerator, denominator);
				}

				cout << "(Just checking, you entered: ";
				a.printRational();
				cout << "-- reduced form)\n";
				isValid = true;
			}
			else
			{
				cout << "Error! Re-Enter a rational number (a/b): ";
			}
		}

		isValid = false;
		cout << "\nEnter a rational number (a/b): ";

		while (!isValid)
		{
			cin >> number;
			length = strlen(number);

			for (int i = 0; i < length; i++)
			{
				if (isdigit(number[i]) || number[i] == '/')
				{
					isRational = true;
				}

				else
				{
					cout << "Only digits are allowed! Please!\n";
					isRational = false;
				}
			}

			if (isRational)
			{
				num = number;
				pos = num.find('/');

				if (pos == -1)
				{
					numerator = stoi(number);
				}
				else
				{
					numerator = stoi(num.substr(0, pos));
					denominator = stoi(num.substr(pos + 1));
				}

				b = Rational(numerator, denominator);
				cout << "(Just checking, you entered: ";
				b.printRational();
				cout << "-- reduced form)\n";
				isValid = true;
			}

			else
			{
				cout << "Error! Re-Enter a rational number (a/b): ";
			}
		}

		cout << "\nResults of Arithmetic operations:\n";

		a.printRational();
		cout << " + ";
		b.printRational();
		c = a.addition(b);
		cout << " = ";
		c.printRational();
		cout << " = ";
		c.printRationalAsDouble();
		cout << "\n";

		a.printRational();
		cout << " - ";
		b.printRational();
		c = a.subtraction(b);
		cout << " = ";
		c.printRational();
		cout << " = ";
		c.printRationalAsDouble();
		cout << "\n";

		a.printRational();
		cout << " * ";
		b.printRational();
		c = a.multiplication(b);
		cout << " = ";
		c.printRational();
		cout << " = ";
		c.printRationalAsDouble();
		cout << "\n";

		a.printRational();
		cout << " / ";
		b.printRational();
		c = a.division(b);
		cout << " = ";
		c.printRational();
		cout << " = ";
		c.printRationalAsDouble();

		cout << "\n\nRun again (y/n)? ";
		cin >> choice;

		while (choice != 'n' && choice != 'y')
		{
			cout << "Please enter 'y' for Yes, or 'n' for No: ";
			cin >> choice;
		}
		isValid = false;

	} while (choice != 'n');

	cout << "\nProgrammer: Pedro Damian Sanchez Jr\n";
	cout << "Please press the <ENTER> key to exit and have a great day...";

	fflush(stdin);
	cin.get();
	return 0;
}