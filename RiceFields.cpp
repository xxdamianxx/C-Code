// Learn how to supply a virtual empire with digital rice as a magistre by calulating the area and perimeter of a rectangular rice plot.

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
    double length;
    double width;

    cout << "Calculating the area and perimeter of your required rectanglar rice plot." << endl;

    cout << endl;

    cout << "Enter the desired length, my lord:" << endl;
    cin >> length;

    cout << endl;

    cout << "Enter the desired width, your grace:" << endl;
    cin >> width;

    cout << endl;

    cout << "The area of the rice plot shall be:" << endl << length*width << endl;

    cout << endl;

    cout << "The perimeter of rice plot shall be:" << endl << (length * 2) + (width * 2) << endl;

    cout << endl;

    cout << "Press the <Enter> key to proceed, your excellency... " << endl;

    cout << endl;

    cout << "Programmed by: Pedro Damian Sanchez Jr" << endl;

    fflush(stdin);

    cin.get();

    return 0;
}