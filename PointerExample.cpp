#include <iostream>

using namespace std;

int main() {

	int n = 1;
	
	//Make p point to the variable n
	int* p = &n;

	//Alocate memory for an int, and store 7 in it
	int* q = new int(7);

	//Deference pointers and print out the values
	cout << "p points to: " << *p << endl;
	cout << "q points to: " << *q << endl;

	//Change values of locations pointed to by p and q

	n = 4;

	*q = 88;

	cout << "now p points to: " << *p << endl;
	cout << "now q points to: " << *q << endl;

	delete q;

	return 0;
}