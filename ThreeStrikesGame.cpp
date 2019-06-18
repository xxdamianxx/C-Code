// Three Strikes is a popular game played for winning a car. There are five chips, each with one of the digits of the price of the car, and three chips with X’s(strikes).
// All the digits of the price are different and unique(only one of its kind). The eight chips are placed in a bag.The contestant picks chips from the bag one by one.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <ctime>
#include <vector>

using namespace std;

class ThreeStrike
{
public:
	ThreeStrike();
	void displayMenu();
	void displayPrice();
	void generatePrice();
	void incrementStrike();
	void incrementCorrectGuess();
	vector<string> myvector;
	string arr[5];
	string bag[8];
	int digitsPlaced;
	int strike;
	int guessCorrect;
};

void ThreeStrike::generatePrice() {
	string p[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	for (int i = 9; i>0; --i)
	{
		int j = rand() % i;
		string temp = p[i];
		p[i] = p[j];
		p[j] = temp;
	}

	for (int i = 0; i < 5; ++i)
	{
		arr[i] = p[i];
	}
	bag[5] = "X";
	bag[6] = "X";
	bag[7] = "X";

	for (int j = 0; j < 5; j++)
	{
		string a = arr[j];
		bag[j] = a;
	}

	for (int j = 0; j < 8; j++)
	{
		myvector.push_back(bag[j]);
	}
}

void ThreeStrike::displayMenu()
{
	cout << "              *********** Welcome to Three Strike Game **********\n";
	cout << "                Pick a chip from a bag, the chip will contain\n";
	cout << "                a digit or a strike, if it's a digit then guess\n";
	cout << "                which position it belongs to the car's price\n\n";
	cout << "                PANEL : _ _ _ _ _ <- this the 0th position\n\n";
	cout << "                POSITION: 4 3 2 1 0\n\n";
	cout << "                Accumulating three strikes will result in losing the game.\n\n";
	cout << "~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~-\n\n";

}

void ThreeStrike::displayPrice() {
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i];
	}
	cout << "\n";
}

ThreeStrike::ThreeStrike() {
	strike = 0;
	digitsPlaced = 0;
}

void ThreeStrike::incrementStrike() {
	cout << "\n\nYou picked a striked!!!\n\n";
	strike++;
}

void ThreeStrike::incrementCorrectGuess() {
	guessCorrect++;
}

using namespace std;

int main()
{
	char choice;
	char play;
	int position;

	do {
		srand(time(0));
		ThreeStrike threeStrike = ThreeStrike();
		int digitsPlaced = 0;
		int track = 8;
		int guessCorrect = 0;
		string panel[5] = { "_", "_", "_", "_", "_" };
		threeStrike.displayMenu();
		threeStrike.generatePrice();
		cout << "The price is hidden: ";
		threeStrike.displayPrice();
		cout << "(Shhhh! It's revealed to you as the programmer's darling!!!)\n";
		cout << "\n~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~-\n\n";
		cout << "Enter 'p' to pick a chip, or any other key to quit the game: ";
		cin >> play;

		if (play == 'p')
		{
			while (play == 'p' && threeStrike.strike != 3 && guessCorrect != 5)
			{
				if (threeStrike.guessCorrect == 5 || threeStrike.strike == 3)
				{
					break;
				}

				cout << "\nStrikes hit: " << threeStrike.strike << "\n";
				cout << "Digits placed: " << digitsPlaced << "\n\n";
				cout << "Panel: $ ";

				for (int i = 0; i < 5; i++)
				{
					cout << panel[i] << " ";
				}
				cout << "\n\t ";

				for (int i = 4; i >= 0; i--)
				{
					cout << i << " ";
				}

				cout << "\n";
				int r = rand() % track;
				string digit = threeStrike.myvector[r];

				if (digit == "X")
				{
					threeStrike.incrementStrike();
					threeStrike.myvector.erase(threeStrike.myvector.begin() + r);
					track--;
				}

				else
				{
					cout << "~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~- ^-~-\n\n";
					cout << "You picked the digit: " << digit << "\n\n";
					cout << "\nWhich position do you think it is? ";
					cin >> position;

					while (cin.fail())
					{
						cout << "Invalid position, input the position again: ";
						cin.clear();
						cin.ignore(256, '\n');
						cin >> position;
					}

					if (threeStrike.arr[4 - position] == digit)
					{
						cout << "Correct, you picked the correct position!!!\n\n";
						panel[4 - position] = threeStrike.arr[4 - position];
						digitsPlaced++;
						threeStrike.myvector.erase(threeStrike.myvector.begin() + r);
						track--;
						threeStrike.incrementCorrectGuess();
					}

					else
					{
						cout << "Sorry! You guessed the wrong position\n\n";
					}
				}

				if (threeStrike.guessCorrect < 5 && threeStrike.strike < 3)
				{
					cout << "Enter 'p' to pick a chip, or any other key to quit the game: ";
					cin >> play;
				}
			}
		}

		else
		{
			cout << "Don't feel good? So sorry as you didn't want to play the game.\n";
		}

		if (threeStrike.guessCorrect == 5)
		{
			cout << "Congratulations! You won the car!!!\n";
		}

		else
		{
			cout << "Sorry you lost the game!\n";
		}

		cout << "The price of the car was: $";
		threeStrike.displayPrice();
		cout << "\nDo you want to play again (y/n) ";
		cin >> choice;
		threeStrike.myvector.clear();
		system("CLS");

	} while (choice != 'n');

	cout << "Thanks for using the game. So Long, farewell!\n";
	cout << "\n\nProgrammer: Pedro Damian Sanchez Jr\n";
	cout << "Please press the <ENTER> key to exit and have a great day...";

	fflush(stdin);
	cin.get();
	return 0;
}