// This is the galaxy's best banking progam.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

class CustomerInfo {
public:
	string name;
	string title;
	string ssn;
	string acc;
	void set(string n, string t, string s, string a);
	string getTitle();
	string getName();
	string getSocial();
	string getAccountID();
};

string CustomerInfo::getTitle() {
	return title;
}

string CustomerInfo::getName() {
	return name;
}

string CustomerInfo::getSocial()
{
	return ssn;
}

string CustomerInfo::getAccountID()
{
	return acc;
}

void CustomerInfo::set(string n, string t, string s, string a)
{
	cout << "\n";
	cout << "\t\t   * === * === * === * === * === * === * === *\n";
	cout << "\t\t   *      Welcome to Nova Prima Banking      *\n";
	cout << "\t\t   * === * === * === * === * === * === * === *\n\n";
	cout << "\t\t      * * * Registration Is Required! * * * \n\n";
	cout << "Please enter your full name: ";
	getline(cin, n);

	cout << "Enter your title (Mr., Mrs., Ms., Dr.): ";
	getline(cin, t);
	while (t != "Mr." &&  t != "Mrs." && t != "Ms." && t != "Dr.")
	{
		cout << "\nERROR!!! a correct title is required!\n\n";

		cout << "Enter your title (Mr., Mrs., Ms., Dr.): ";
		getline(cin, t);
	}


	bool check = false;
	while (!check)
	{
		cout << "Enter your SSN (in the format of 123-45-6789): ";
		getline(cin, s);
		string usersocial = s;
		if (usersocial.length() == 11)
		{
			if (usersocial[3] == '-' && usersocial[6] == '-')
			{
				usersocial = usersocial.replace(3, 1, "");
				usersocial = usersocial.replace(6, 1, "");
				for (int i = 0; i < usersocial.length(); i++)
				{
					if (isdigit(usersocial[i]))
					{
						check = true;
					}
				}
			}
		}

		if (check == false)
		{
			cout << "\nError!!! use the correct format AAA-GG-SSSS\n\n";
		}
	}

	cout << "Enter your account ID: ";
	getline(cin, a);

	name = n;
	title = t;
	ssn = s;
	acc = a;

	cout << endl;
	cout << endl;
	cout << "\t Welcome, " << title << " " << name << ", how is your day? Ready to start?" << endl;
	cout << endl;
	cout << "\t\t Press <Enter> to use our banking services ...";
	cout << endl;
	cin.get();



}


//BANK SERVICE MENU
void bankServiceMenu()
{
	cout << "\t\t\t\t Bank Services Menu\n";
	cout << "\t\t\t\t ------------------\n";
	cout << "\t\t\t\t 1) Checking Account\n";
	cout << "\t\t\t\t 2) Savings Account\n";
	cout << "\t\t\t\t 3) End of services\n\n";
}

void displayAccActivities()
{

	cout << "\t\t\t\t Account Activities\n";
	cout << "\t\t\t\t ==================\n";
	cout << "\t\t\t\t a) ---Deposit----\n";
	cout << "\t\t\t\t b) ---Withdraw---\n";
	cout << "\t\t\t\t c) ---Transfer---\n";
	cout << "\t\t\t\t d) ---Balance----\n";
	cout << "\t\t\t\t e) Personal Check\n";
	cout << "\t\t\t\t f) ---Interest---\n";
	cout << "\t\t\t\t g) ---Statement--\n";
	cout << "\t\t\t\t h) -----Done-----\n\n";
	cout << "\t\t\t\t Enter your choice: ";
}




class Saving {
public:
	double savingBalance = 0;
	double totalBalance = 0;
	double savingDividend = 0;
	double savingBalancePlusInterest = 0;
	void setBalance(double balance);
	void deposits(double accDep);
	void withdrawal(double w);
	double getBalance();
	void interest();


};



double Saving::getBalance() {
	return savingBalance;
}

void Saving::setBalance(double balance)
{
	savingBalance = balance;
}


//DEPOSITS FUNCTION
void Saving::deposits(double accDep)
{
	double newBalance;
	totalBalance += accDep;
	totalBalance += savingBalance;
	newBalance = totalBalance;
	setBalance(newBalance);
	cout << "Added successfully to Savings!\n";
	cout << "Savings balance: $" << savingBalance << "\n";
}

//WITHDRAWAL FUNCTION
void Saving::withdrawal(double w)
{
	//Store new balance in variable
	if (savingBalance - w < 25.00)
	{
		cout << "Error - insufficent funds to debit $" << w << "\n";
		cout << "NOTE: Savings account must have at least $ 25.00 left to be active.\n";
		cout << "Withdrawal cancelled!\n";
	}
	else {
		double newBalance = 0;
		newBalance = savingBalance - w;
		setBalance(newBalance);
	}
	cout << "Saving balance: $" << savingBalance << "\n";

}


void Saving::interest()
{
	if (savingBalance == savingBalancePlusInterest)
	{
		cout << "No change in balance since last interest calculation. No new interest earned\n";
	}
	savingDividend = savingBalance * .0375;
	savingBalancePlusInterest = savingBalance + savingDividend;
	cout << "Checking dividend:  $" << savingDividend << "\n";
	cout << "Checking Balance: $" << savingBalancePlusInterest << "\n";
	setBalance(savingBalancePlusInterest);
}




class Checking {
public:
	double checkbalance = 0;
	double totalBalance = 0;
	int transferToSaving = 0;
	int numberOfDeposits = 0;
	double checkingDividend = 0;
	double checkBalancePlusInterest = 0;
	int checkBounced = 0;
	int checkWritten = 0;
	void setBalance(double balance);
	void deposits(double accDep);
	void withdrawal(double w);
	void personalCheck(double w);
	double getBalance();
	void interest();

};

void Checking::interest()
{
	if (checkbalance == checkBalancePlusInterest)
	{
		cout << "No change in balance since last interest calculation. No new interest earned\n";
	}
	checkingDividend = checkbalance * .025;
	checkBalancePlusInterest = checkbalance + checkingDividend;
	cout << "Checking dividend:  $" << checkingDividend << "\n";
	cout << "Checking Balance: $" << checkBalancePlusInterest << "\n";
	setBalance(checkBalancePlusInterest);
}


void Checking::personalCheck(double w)
{
	double newBalance = 0;
	if (w <= checkbalance)
	{

		cout << "Deducted successfully from Checking!\n";
		if (checkWritten > 1)
		{
			cout << "Charge for signed checks beyond 1: $0.10\n";
			cout << "You have written " << checkWritten << " check(s)\n";
			newBalance = checkbalance - 0.10 - w;
			setBalance(newBalance);
		}
		else
		{
			cout << "You have written " << (checkWritten + 1) << " check(s)\n";
			newBalance = checkbalance - w;
			setBalance(newBalance);
		}
		checkWritten++;
	}
	else
	{
		cout << "\t\t\t\tError! Not enough money to withdraw.\n";
		cout << "\t\t\t\tYou have bounced a check !!\n";
		cout << "Bounced Check Fee: $15.00\n";
		newBalance = checkbalance - 15.00;
		setBalance(newBalance);
		checkBounced++;

	}
	cout << "Checking balance: $" << checkbalance << "\n";
}


double Checking::getBalance() {
	return checkbalance;
}

void Checking::setBalance(double balance)
{
	checkbalance = balance;
}



//DEPOSITS FUNCTION
void Checking::deposits(double accDep)
{
	//Store new balance in variable
	double newBalance = 0;

	//This stores total as more deposits are added


	if (numberOfDeposits == 0)
	{
		newBalance += accDep;
		newBalance -= 5.00;
		newBalance += checkbalance;
		setBalance(newBalance);

	}
	else
	{
		newBalance += accDep;
		newBalance += checkbalance;
		setBalance(newBalance);
	}
	cout << setprecision(2) << fixed << showpoint;
	cout << "Added successfully to Checking!\n";
	cout << "Checking balance: $" << checkbalance << "\n";

	numberOfDeposits++;


}

//WITHDRAWAL FUNCTION
void Checking::withdrawal(double w)
{
	double newBalance = 0;
	if (checkbalance - w < 0){
		cout << "Error - insufficent funds to debit $" << w << "\n";
		cout << "Withdrawal cancelled!\n";
	}
	else {
		cout << "Deducted successfully from Checking!\n";
		newBalance = checkbalance - w;
		setBalance(newBalance);
	}
	cout << "Checking balance: $" << checkbalance << "\n";
}



void transfertoSaving(double t, Checking& check, Saving& save)
{
	if (check.checkbalance - t < 0)
	{
		cout << "Error - insufficent funds to debit $" << t << "\n";
		cout << "Transfer cancelled\n";
	}
	else
	{
		cout << "Deducted successfully from Checking!\n";
		cout << "Added successfully to Saving\n";
		double newCheckBalance = 0;
		double newSaveBalance = 0;
		newCheckBalance = check.checkbalance - t;
		check.setBalance(newCheckBalance);
		newSaveBalance = save.savingBalance + t;
		save.setBalance(newSaveBalance);
	}
	cout << "Checking balance: $" << check.checkbalance << "\n";
	cout << "Saving balance: $" << save.savingBalance << "\n";
}


void transfertoChecking(double t, Checking& check, Saving& save) {
	if (save.savingBalance - t < 25.00)
	{
		cout << "Error - insufficent funds to debit $" << t << "\n";
		cout << "NOTE: Savings account must have at least $ 25.00 left to be active.\n";
		cout << "Transfer cancelled!\n";
	}
	else
	{
		cout << "Deducted successfully from Savings!\n";
		cout << "Added successfully to Checking\n";
		double newCheckBalance = 0;
		double newSaveBalance = 0;
		newSaveBalance = save.savingBalance - t;
		save.setBalance(newSaveBalance);
		newCheckBalance = check.checkbalance + t;
		check.setBalance(newCheckBalance);
	}
	cout << "Checking balance: $" << check.checkbalance << "\n";
	cout << "Saving balance: $" << save.savingBalance << "\n";
}





void displayStatement(CustomerInfo person, Checking check, Saving save, int transferToChecking, int transferToSaving)
{

	cout << setprecision(2) << fixed << showpoint;
	cout << "\t\t\t\t *** Statement ***\n " << endl;
	cout << "Customer Name: " << person.getTitle() << " " << person.getName() << endl;
	cout << "Social Security Number: " << person.getSocial() << endl;
	cout << "Customer ID: " << person.getAccountID() << endl;
	cout << "Checks written: " << check.checkWritten << endl;
	cout << "Checks bounced: " << check.checkBounced << endl;
	cout << "Transfers to Checking: " << transferToChecking << endl;
	cout << "Transfers to savings: " << transferToSaving << endl;
	cout << "Checking dividend: $" << check.checkingDividend << endl;
	cout << "Checking balance: $" << check.checkbalance << endl;
	cout << "Savings dividend: $" << save.savingDividend << endl;
	cout << "Savings balance: $" << save.savingBalance << endl;
	cin.ignore();
	cout << "\t\t\t Press <Enter> key to continue...";
	fflush(stdin);
	cin.get();
}

int _tmain(int argc, _TCHAR* argv[])
{
	string name, title, ssn, acc;
	CustomerInfo person;
	Checking check;
	Saving save;
	int transferToChecking = 0;
	int transferToSaving = 0;
	int bankServiceChoice;
	double deposit = 0.0;
	double withdraw = 0.0;
	char bankServiceContinue = 'y', openAccount, accActChoice;
	person.set(name, title, ssn, acc);

	do
	{
		system("cls");
		bankServiceMenu();
		cout << "\t\t\t\t Enter your choice: ";
		cin >> bankServiceChoice;
		while (bankServiceChoice < 1 || bankServiceChoice > 3)
		{
			system("cls");
			bankServiceMenu();
			cout << "\t\t ERROR! Invalid value. Re-enter your selection: ";
			cin >> bankServiceChoice;
		}
		//Run checking account class 
		if (bankServiceChoice == 1)
		{
			cout << "\n\nOpen/Manage the Checking account (y/n)? ";
			cin >> openAccount;
			if (openAccount == 'y')
			{
				do
				{
					system("cls");
					cout << endl;
					cout << endl;
					cout << "\t\t\t\t **** Checking ****\n";
					displayAccActivities();
					cin >> accActChoice;
					if (accActChoice == 'a')
					{
						cout << endl;
						cout << endl;
						cout << "\t\t\t\t*** Deposit ***\n";
						cout << "Enter amount to deposit: ";
						cin >> deposit;
						check.deposits(deposit);
						cin.ignore();
						cout << "\t\t\t Press <Enter> key to end the program...\n";
						fflush(stdin);
						cin.get();
					}
					else if (accActChoice == 'b')
					{
						cout << endl;
						cout << endl;
						cout << "\t\t\t\t*** Withdraw ***\n";
						cout << "Enter amount to withdraw: ";
						cin >> withdraw;
						check.withdrawal(withdraw);
						cin.ignore();
						cout << "\t\t\t Press <Enter> key to end the program...\n";
						fflush(stdin);
						cin.get();
					}
					else if (accActChoice == 'c')
					{
						int transferchoice;
						cout << endl;
						cout << endl;
						cout << "\t\t\\t*** Transfer ***\n";
						cout << "\t\t\t1) from Checking to Savings\n";
						cout << "\t\t\t2) from Savings to Checking\n";
						cout << "\t\t\t\tEnter your choice: ";
						cin >> transferchoice;
						while (transferchoice != 1 && transferchoice != 2)
						{
							cout << "\t\t\tError! Invalid value. Re-enter your choice: ";
							cin >> transferchoice;
						}
						double transferAmount = 0;
						cout << "Enter amount to transfer? ";
						cin >> transferAmount;
						if (transferchoice == 1)
						{

							transfertoSaving(transferAmount, check, save);
							transferToSaving++;
						}
						else if (transferchoice == 2)
						{

							if (transferToChecking > 1)
							{
								transferAmount -= 1;
							}
							transfertoChecking(transferAmount, check, save);
							transferToChecking++;
						}

						cin.ignore();
						cout << "\t\t Press <Enter> key to end the program ...";
						fflush(stdin);
						cin.get();

					}
					else if (accActChoice == 'd')
					{
						cout << "\t\t\t\t*** Balance ***\n";
						cout << "Checking Balance: $" << check.getBalance() << "\n";
						cin.ignore();
						cout << "\t\t\t Press <Enter> key to end the program...\n";
						fflush(stdin);
						cin.get();
					}
					else if (accActChoice == 'e')
					{
						cout << "\t\t\t\t*** Personal Check ***\n";
						cout << "\t\t\t\tEnter amount to withdraw: ";
						cin >> withdraw;
						check.personalCheck(withdraw);
						cin.ignore();
						cout << "\t\t\t Press <Enter> key to end the program...\n";
						fflush(stdin);
						cin.get();
					}
					else if (accActChoice == 'f')
					{
						cout << endl;
						cout << endl;
						cout << "\t\t\t*** Interest ***\n";
						check.interest();
						cin.ignore();
						cout << "\t\t\t Press <Enter> key to end the program...\n";
						fflush(stdin);
						cin.get();

					}
					else if (accActChoice == 'g')
					{
						displayStatement(person, check, save, transferToChecking, transferToSaving);
					}


				} while (accActChoice != 'h');
				cin.ignore();
				cout << setprecision(2) << fixed << showpoint;
				cout << "\t\t\tEnd of Checking account Option.\n";
				cout << "Number of checks signed: " << check.checkWritten << "\n";
				cout << "Number of checks bounced: " << check.checkBounced << "\n";
				cout << "Checking dividend: $" << check.checkingDividend << "\n";
				cout << "Checking Balance: $" << check.checkbalance << "\n";
				cout << "\t\t\t Press <Enter> key to end the program...";
				fflush(stdin);
				cin.get();
			}
			else
			{
				cin.ignore();
				cout << "\n\nSelect another service if you like ...\n\n";
				cout << "\t\t Press <Enter> key to end the program ...";
				fflush(stdin);
				cin.get();
			}
		}
		//Run Savings account class
		else if (bankServiceChoice == 2)
		{
			cout << "\n\nOpen/Manage the Savings account (y/n)? ";
			cin >> openAccount;

			if (openAccount == 'y')
			{
				do
				{
					system("cls");
					cout << endl;
					cout << endl;
					cout << "\t\t\t\t **** Savings *****\n";
					displayAccActivities();
					cin >> accActChoice;

					if (accActChoice == 'a')
					{
						cout << "Enter amount to deposit: ";
						cin >> deposit;
						save.deposits(deposit);
						cin.ignore();
						cout << "\t\t\t Press <Enter> key to end the program...";
						fflush(stdin);
						cin.get();
					}
					else if (accActChoice == 'b')
					{
						cout << endl;
						cout << endl;
						cout << "\t\t\t\t*** Withdraw ***\n";
						cout << "Enter amount to withdraw: ";
						cin >> withdraw;
						save.withdrawal(withdraw);
						cin.ignore();
						cout << "\t\t\t Press <Enter> key to end the program...\n";
						fflush(stdin);
						cin.get();
					}
					else if (accActChoice == 'c')
					{
						int transferchoice;
						cout << endl;
						cout << endl;
						cout << "\t\t\t*** Transfer ***\n";
						cout << "\t\t\t1) from Checking to Savings\n";
						cout << "\t\t\t2) from Savings to Checking\n";
						cout << "\t\t\t\tEnter your choice: ";
						cin >> transferchoice;
						while (transferchoice != 1 && transferchoice != 2)
						{
							cout << "\t\t\tError! Invalid value. Re-enter your choice: ";
							cin >> transferchoice;
						}
						double transferAmount = 0;
						cout << "Enter amount to transfer? ";
						cin >> transferAmount;
						if (transferchoice == 1)
						{

							transfertoSaving(transferAmount, check, save);
							transferToSaving++;
						}
						else if (transferchoice == 2)
						{

							if (transferToChecking > 1)
							{
								transferAmount -= 1;
							}
							transfertoChecking(transferAmount, check, save);
							transferToChecking++;
						}

						cin.ignore();
						cout << "\t\t Press <Enter> key to end the program ...";
						fflush(stdin);
						cin.get();

					}
					else if (accActChoice == 'd')
					{
						cout << endl;
						cout << endl;
						cout << "\t\t\t\t*** Balance ***\n";
						cout << "Saving Balance: $" << save.getBalance() << "\n";
						cin.ignore();
						cout << "\t\t\t Press <Enter> key to end the program...\n";
						fflush(stdin);
						cin.get();
					}
					else if (accActChoice == 'e')
					{
						cout << endl;
						cout << endl;
						cout << "\t\t\t\t*** Personal Check ***\n";
						cout << "Error. You can not write a check from a savings account!\n";
						cout << "Savings balance: $" << save.savingBalance << "\n";
						cin.ignore();
						cout << "\t\t\t Press <Enter> key to end the program...\n";
						fflush(stdin);
						cin.get();
					}
					else if (accActChoice == 'f')
					{
						cout << endl;
						cout << endl;
						cout << "\t\t\t*** Interest ***\n";
						save.interest();
						cin.ignore();
						cout << "\t\t\t Press <Enter> key to end the program...\n";
						fflush(stdin);
						cin.get();

					}

					else if (accActChoice == 'g')
					{
						displayStatement(person, check, save, transferToChecking, transferToSaving);
					}

				} while (accActChoice != 'h');
				cin.ignore();
				cout << "End of Savings account Option.\n";
				cout << "Number of transfer to checking: " << "\n";
				cout << "Saving dividend: $" << save.savingDividend << "\n";
				cout << "Savings Balance: $" << save.savingBalance << "\n";
				cout << "\t\t\t Press <Enter> key to end the program...";
				fflush(stdin);
				cin.get();
			}
			else
			{
				cin.ignore();
				cout << "Select another service if you like ...\n";
				cout << "\t\t Press <Enter> key to end the program ...";
				fflush(stdin);
				cin.get();
			}
		}
		else if (bankServiceChoice == 3)
		{
			cout << endl << "\t\t Thanks for visiting our bank, " << person.getTitle() << " " << person.getName() << endl;
			cout << "\t\t\t We hope you are happy with our service." << endl;
			cout << "\t\tDid you miss anything and want to go back (y/n)? ";
			cin >> bankServiceContinue;

			while (toupper(bankServiceContinue) != 'Y' && toupper(bankServiceContinue) != 'N')
			{
				cout << endl << endl;
				cout << "The entry was invalid. Please enter Y or N: ";
				cin >> bankServiceContinue;
			}
		}

	} while (toupper(bankServiceContinue) != 'N');

	return 0;
}