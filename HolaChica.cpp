// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int edad;
	string nombre;

	cout << "Hola Chica, mi nombre es Damian Sanchez, programador extraordinario.\n\nComo te llamas?\n";
	cin >> nombre;
	cout << endl;

	cout << "Hola " << nombre << ", mucho gusto en conoser te.\n\nY cual es tu edad?\n";
	cin >> edad;
	cout << endl;

	if (edad < 18)
	{
		cout << "Ay guey, hablamos despues de que cumples 18, bye.";
	}

	if (edad == 18)
	{
		cout << "Mmmm, que rico, bebe.";
	}

	if (edad > 19 || edad < 26)
	{
		cout << "Estas un poquito mas joven que yo, pero que rico.";
	}

	else
	{
		cout << "Estas muy grande para mi, bye.";
	}

	fflush(stdin);
	cin.get();
	return 0;
}

