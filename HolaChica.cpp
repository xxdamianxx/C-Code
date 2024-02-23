/*
* HolaChica.cpp
* This program is a Spanish Chatbot.
* 
* Created by Pedro Damian Sanchez Jr. on 02/22/2017
* Copyright © 2024. All rights reserved.
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int edad;
	string nombre;

	cout << "Hola Chica! Mi nombre es Pedro Damian Sanchez Jr, programador extraordinario.\n\n\nComo te llamas?\n";
	cout << "Escriba tu nombre: "; getline(cin, nombre);
	cout << endl;

	cout << "Hola " << nombre << ", mucho gusto en conoser te.\n\nY cual es tu edad?\n";
	cout << "Introduzca su edad: "; cin >> edad;
	cout << endl;

	if (edad < 18) {
		cout << "Ay guey! Hablamos despues de que cumples 18, bye.\n";
	}
	else if (edad == 18) {
		cout << "Mmmm. Que rico, bebe.\n";
	}
	else if (edad >= 19 && edad <= 36) {
		cout << "Estas un poquito mas joven que yo, pero que rico.\n";
	}
	else {
		cout << "Estas muy grande para mi, bye.\n";
	}
	cout << endl;

	fflush(stdin);
	cin.get();
	return 0;
}
