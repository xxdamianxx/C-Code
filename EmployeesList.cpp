// This program serves as a digital employee registration log owned and operated exclusively by the TORUS MHD CORPERATION and its affiliates.
//

#include "stdafx.h"
#include<iostream>
#include <fstream>
#include <string>

using namespace std;

struct node
{
	int id;
	string firstName;
	string lastName;
	int SSN;
	double wage;
	string department;
	string date;

	struct node *next;
}*start;


class single_llist
{
public:
	node* create_node(int, string, string, int, double, string, string);
	void insert_begin(int, string, string, int, double, string, string);
	void delete_pos(int);
	void sort();
	bool search(int);
	void searchInfo(int);
	void update(int, string, string, int, double, string, string);
	void display();
	void savetoFile(string);
	single_llist()
	{
		start = NULL;
	}
};



string convertDate(int month, int day, int year)
{
	string date = "";
	if (month == 1)
	{
		date = "January " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 2)
	{
		date = "February " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 3)
	{
		date = "March " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 4)
	{
		date = "April";
	}
	else if (month == 5)
	{
		date = "May " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 6)
	{
		date = "June " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 7)
	{
		date = "July " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 8)
	{
		date = "August " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 9)
	{
		date = "September " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 10)
	{
		date = "October " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 11)
	{
		date = "November " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 12)
	{
		date = "December " + to_string(day) + ", " + to_string(year);
	}
	return date;

}


bool checkdate(int m, int d, int y)
{
	string month = "";
	if (m == 1)
	{
		month = "January";
	}
	else if (m == 2)
	{
		month = "February";
	}
	else if (m == 3)
	{
		month = "March";
	}
	else if (m == 4)
	{
		month = "April";
	}
	else if (m == 5)
	{
		month = "May";
	}
	else if (m == 6)
	{
		month = "June";
	}
	else if (m == 7)
	{
		month = "July";
	}
	else if (m == 8)
	{
		month = "August";
	}
	else if (m == 9)
	{
		month = "September";
	}
	else if (m == 10)
	{
		month = "October";
	}
	else if (m == 11)
	{
		month = "November";
	}
	else if (m == 12)
	{
		month = "December";
	}
	//gregorian dates started in 1582
	if (!(1582 <= y)) {
		return false;
	}
	if (!(m >= 1 && m <= 12)) {
		cout << m << " is not a valid month.\n";
		return false;
	}
	if (!(d >= 1 && d <= 31)) {
		cout << y << " is not a Leap Year; 31 is not a valid day of " + month + ". It is invalid date.\n";
		cout << "Error!!! The entered date is invalid! Try again.\n";
		return false;
	}
	if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
	{
		cout << y << " is not a Leap Year; 31 is not a valid day of " + month + ". It is invalid date.\n";
		cout << "Error!!! The entered date is invalid! Try again.\n";
		return false;
	}
	if ((d == 30) && (m == 2))
	{
		cout << y << " is not a Leap Year; 31 is not a valid day of " + month + ". It is invalid date.\n";
		cout << "Error!!! The entered date is invalid! Try again.\n";
		return false;
	}
	if ((m == 2) && (d == 29) && (y % 4 != 0))
	{
		cout << y << " is not a Leap Year; 31 is not a valid day of " + month + ". It is invalid date.\n";
		cout << "Error!!! The entered date is invalid! Try again.\n";
		return false;
	}
	if ((m == 2) && (d == 29) && (y % 400 == 0)) {
		return true;
	}
	if ((m == 2) && (d == 29) && (y % 100 == 0))
	{
		cout << y << " is not a Leap Year; 31 is not a valid day of " + month + ". It is invalid date.\n";
		cout << "Error!!! The entered date is invalid! Try again.\n";
		return false;
	}
	if ((m == 2) && (d == 29) && (y % 4 == 0))
	{
		return true;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int month;
	int day;
	int year;
	string filename;
	ifstream infile;
	string exist;
	string reuse;
	bool found = false;
	int id;
	string firstName;
	string lastName;
	string SSN;
	int ssn;
	string department;
	double wage;
	string date;

	single_llist sl;
	start = NULL;
	cout << "\n\t\t**** ~-~ = ~-~ = ~-~ = ~-~ = ~-~ = ~-~ = ~-~ = ~-~ ****\n";
	cout << "\t\t****                                               ****\n";
	cout << "\t\t**         Torus MHD Corperate Employee List         **\n";
	cout << "\t\t****                                               ****\n";
	cout << "\t\t**** ~-~ = ~-~ = ~-~ = ~-~ = ~-~ = ~-~ = ~-~ = ~-~ ****\n\n";
	cout << "Reuse existing data previously saved in external file (y/n)? ";
	cin >> reuse;
	while (!(reuse == "y" || reuse == "Y" || reuse == "n" || reuse == "N"))
	{
		cout << "\tPlease answer with either 'y' or 'n'\n";
		cout << "Reuse existing data previously saved in external file (y/n)? ";
		cin >> reuse;
	}

	if (reuse == "y" || reuse == "Y")
	{

		do
		{
			cout << "\tEnter file name to read data:";
			cin >> filename;
			infile.open(filename);
			if (!infile)
			{
				found = false;
				cout << "Error opening file for reading! Not Found.\n";
			}
			else
			{
				found = true;
				cout << "\tAll data were read back from file \"" << filename << "\" successfully!";
				break;
			}
			cout << "Still want to open a file for reading data (y/n)?";
			cin >> exist;
		} while (exist != "n" && exist != "N");
	}


	if (found)
	{
		while (!infile.eof())
		{
			infile >> id >> firstName >> lastName >> ssn >> wage >> department >> date;
			sl.insert_begin(id, firstName, lastName, ssn, wage, department, date);
		}
	}
	system("CLS");
	int menuChoice;
	do
	{
		system("CLS");
		cout << "\t\t\t\tM E N U\n";
		cout << "\t\t\t\t=======\n\n";
		cout << "\t\t\t1. Add New Employee\n";
		cout << "\t\t\t2. Search Existing Employee\n";
		cout << "\t\t\t3. Display Employee List\n";
		cout << "\t\t\t4. Update Existing Employee\n";
		cout << "\t\t\t5. Delete Existing Employee\n";
		cout << "\t\t\t6. Quit\n\n";

		cout << "\t\tEnter your choice (1-6): ";
		cin >> menuChoice;
		while (menuChoice < 1 || menuChoice > 6)
		{
			cout << "Error! Invalid Choice. Try again: ";
			cin >> menuChoice;
		}

		if (menuChoice == 1)
		{
			cout << "\t\tEnter employee's ID (1-100): ";
			cin >> id;
			while (sl.search(id)) {
				cout << "The ID has already been used! Cannot overwrite the ID.\n";
				cout << "\t\tEnter employee's ID (1-100): ";
				cin >> id;
			}
			while (id < 1 || id > 100)
			{
				cout << "Error! Invalid ID Number. Try again: ";
				cin >> id;
			}
			cout << "\t\tEnter first name: ";
			cin >> firstName;
			cout << "\t\tEnter last name: ";
			cin >> lastName;
			cout << "\t\tEnter Last 4 digits of SSN: ";
			cin >> SSN;
			while (SSN.length() != 4)
			{
				cout << "Error! Invalid SSN. Must be 4 digits. Try again: ";
				cin >> SSN;
			}
			ssn = stoi(SSN);
			cout << "\t\tEnter hourly wage: ";
			cin >> wage;
			cout << "\t\tEnter Department: ";
			cin >> department;
			bool dateValid = false;
			do
			{
				cout << "\t\tEnter a date (mm/dd/yyyy): ";
				cin >> date;
				if (date.length() == 10)
				{
					month = stoi(date.substr(0, 2));
					day = stoi(date.substr(3, 2));
					year = stoi(date.substr(6));
					dateValid = checkdate(month, day, year);
				}
				else
				{
					cout << "\t\t" << date << " is NOT a Valid Date! Try again.\n";
				}
			} while (!dateValid);
			sl.insert_begin(id, firstName, lastName, ssn, wage, department, date);
		}
		else if (menuChoice == 2)
		{
			cout << "\n\t\tEnter employee's ID to search: ";
			cin >> id;
			if (sl.search(id))
			{
				sl.searchInfo(id);
			}
			else
			{
				cout << "\n\t\tError! There was no employee with that ID\n";
			}
			cout << "\n\t\t\tPress <Enter> key to continue...\n";
			cin.get();
			cin.ignore();

		}
		else if (menuChoice == 3)
		{
			sl.sort();
			sl.display();
			cout << "\t\tPress <Enter> key to continue ...";
			cin.get();
			cin.ignore();
		}
		else if (menuChoice == 4)
		{
			cout << "\n\t\tEnter employee's ID to update: ";
			cin >> id;
			if (sl.search(id))
			{
				sl.searchInfo(id);
				cout << "\n\n\t\tEnter first name: ";
				cin >> firstName;
				cout << "\t\tEnter last name: ";
				cin >> lastName;
				cout << "\t\tEnter Last 4 digits of SSN: ";
				cin >> SSN;
				while (SSN.length() != 4)
				{
					cout << "Error! Invalid SSN. Must be 4 digits. Try again: ";
					cin >> SSN;
				}
				ssn = stoi(SSN);
				cout << "\t\tEnter hourly wage: ";
				cin >> wage;
				cout << "\t\tEnter Department: ";
				cin >> department;
				bool dateValid = false;
				do
				{
					cout << "\t\tEnter a date (mm/dd/yyyy): ";
					cin >> date;
					if (date.length() == 10)
					{
						month = stoi(date.substr(0, 2));
						day = stoi(date.substr(3, 2));
						year = stoi(date.substr(6));
						dateValid = checkdate(month, day, year);
					}
					else
					{
						cout << "\t\t" << date << " is NOT a Valid Date! Try again.\n";
					}
				} while (!dateValid);
				sl.update(id, firstName, lastName, ssn, wage, department, date);
			}
			else
			{
				cout << "\n\t\tError! There was no employee with that ID\n";
			}
			cout << "\n\t\t\tPress <Enter> key to continue...\n";
			cin.get();
			cin.ignore();
		}
		else if (menuChoice == 5)
		{
			cout << "\t\tEnter employee's ID to delete: ";
			cin >> id;
			if (sl.search(id))
			{

				sl.delete_pos(id);
			}
			else
			{
				cout << "Error! There was no employee with that ID\n";
			}
			cout << "\n\t\t\tPress <Enter> key to continue...\n";
			cin.get();
			cin.ignore();
		}


	} while (menuChoice != 6);

	char externalFile;
	cout << "Do you want to save current data to an external file (y/n)? ";
	cin >> externalFile;
	if (externalFile == 'y')
	{
		cout << "Enter file name to save data: ";
		cin >> filename;
		sl.savetoFile(filename);
		cout << "All data were saved to file\"" + filename + "\" successfully!\n";
	}
	cout << "\n\nPress <Enter> key to continue...\n\n\n";
	cout << "Programmer: Pedro Damian Sanchez Jr - CISC 192/C++ Programming.\n";
	cout << "Thanks for using the application. So Long, farewell!\n";
	cin.get();
	cin.ignore();

	/*
	month = stoi(date.substr(0, 2));
	while (month <= 0 || month >= 12)
	{
	cout << month << "is not a valid month.\n";
	cout << "Enter a date (mm/dd/yyyy): " << endl;
	cin >> date;
	}
	day = stoi(date.substr(3, 2));
	year = stoi(date.substr(6));
	*/





	//sl.insert_begin(40, "Andrew", "Hoang",9832,12.00,"CS","12/11/1200");
	//sl.insert_begin(45, "Hoang");




	/*
	int choice, nodes, element, position, i;
	single_llist sl;
	start = NULL;
	while (1)
	{
	cout << endl << "---------------------------------" << endl;
	cout << endl << "Operations on singly linked list" << endl;
	cout << endl << "---------------------------------" << endl;
	cout << "1.Insert Node at beginning" << endl;
	cout << "2.Insert node at last" << endl;
	cout << "3.Insert node at position" << endl;
	cout << "4.Sort Link List" << endl;
	cout << "5.Delete a Particular Node" << endl;
	cout << "6.Update Node Value" << endl;
	cout << "7.Search Element" << endl;
	cout << "8.Display Linked List" << endl;
	cout << "9.Reverse Linked List " << endl;
	cout << "10.Exit " << endl;
	cout << "Enter your choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	cout << "Inserting Node at Beginning: " << endl;
	sl.insert_begin();
	cout << endl;
	break;
	case 2:
	cout << "Inserting Node at Last: " << endl;
	sl.insert_last();
	cout << endl;
	break;
	case 3:
	cout << "Inserting Node at a given position:" << endl;
	sl.insert_pos();
	cout << endl;
	break;
	case 4:
	cout << "Sort Link List: " << endl;
	sl.sort();
	cout << endl;
	break;
	case 5:
	cout << "Delete a particular node: " << endl;
	sl.delete_pos();
	break;
	case 6:
	cout << "Update Node Value:" << endl;
	sl.update();
	cout << endl;
	break;
	case 7:
	cout << "Search element in Link List: " << endl;
	sl.search();
	cout << endl;
	break;
	case 8:
	cout << "Display elements of link list" << endl;
	sl.display();
	cout << endl;
	break;
	case 9:
	cout << "Reverse elements of Link List" << endl;
	sl.reverse();
	cout << endl;
	break;
	case 10:
	cout << "Exiting..." << endl;
	exit(1);
	break;
	default:
	cout << "Wrong choice" << endl;
	}
	}*/
}

/*
* Creating Node
*/
node *single_llist::create_node(int id, string firstName, string lastName, int ssn, double wage, string department, string date)
{
	struct node *temp, *s;
	temp = new(struct node);
	if (temp == NULL)
	{
		cout << "Memory not allocated " << endl;
		return 0;
	}
	else
	{
		temp->id = id;
		temp->firstName = firstName;
		temp->lastName = lastName;
		temp->SSN = ssn;
		temp->wage = wage;
		temp->department = department;
		temp->date = date;
		temp->next = NULL;
		return temp;
	}
}

/*
* Inserting element in beginning
*/
void single_llist::insert_begin(int id, string firstName, string lastName, int ssn, double wage, string department, string date)
{
	struct node *temp, *p;
	temp = create_node(id, firstName, lastName, ssn, wage, department, date);
	if (start == NULL)
	{
		start = temp;
		start->next = NULL;
	}
	else
	{
		p = start;
		start = temp;
		start->next = p;
	}
}


/*
* Sorting Link List
*/
void single_llist::sort()
{
	struct node *ptr, *s;
	int value;
	if (start == NULL)
	{
		return;
	}
	ptr = start;
	while (ptr != NULL)
	{
		for (s = ptr->next; s != NULL; s = s->next)
		{
			if (ptr->id > s->id)
			{
				value = ptr->id;
				ptr->id = s->id;
				s->id = value;
			}
		}
		ptr = ptr->next;
	}
}

/*
* Delete element at a given position
*/
void single_llist::delete_pos(int id)
{
	struct node *e;
	e = start;
	int pos = 0;
	while (e != NULL)
	{
		if (e->id == id)
		{
			pos++;
		}
		e = e->next;
	}
	int counter = 0;
	if (start == NULL)
	{
		return;
	}
	struct node *s, *ptr = NULL;
	s = start;
	if (pos == 1)
	{
		start = s->next;
	}
	else
	{
		while (s != NULL)
		{
			s = s->next;
			counter++;
		}
		if (pos > 0 && pos <= counter)
		{
			s = start;
			for (int i = 1; i < pos; i++)
			{
				ptr = s;
				s = s->next;
			}
			ptr->next = s->next;
		}
		free(s);
	}
}

/*
* Update a given Node
*/
void single_llist::update(int id, string firstName, string lastName, int ssn, double wage, string department, string date)
{
	int value, pos, i;
	bool flag = false;
	struct node *s;
	s = start;
	while (s != NULL)
	{
		if (s->id == id)
		{
			s->firstName = firstName;
			s->firstName = firstName;
			s->lastName = lastName;
			s->SSN = ssn;
			s->wage = wage;
			s->department = department;
			s->date = date;
		}
		s = s->next;
	}


	/*
	cout << "Enter the node postion to be updated: ";
	cin >> pos;
	cout << "Enter the new value: ";
	cin >> value;
	struct node *s, *ptr;
	s = start;
	if (pos == 1)
	{
	start->id = value;
	}
	else
	{
	for (i = 0; i < pos - 1; i++)
	{
	if (s == NULL)
	{
	cout << "There are less than " << pos << " elements";
	return;
	}
	s = s->next;
	}
	s->id = value;
	}
	*/
}

/*
* Searching an element
*/
bool single_llist::search(int id)
{
	bool flag = false;
	if (start == NULL)
	{
		//cout << "List is empty" << endl;
		return false;
	}
	//cout << "Enter the value to be searched: ";
	//cin >> value;
	struct node *s;
	s = start;
	while (s != NULL)
	{
		if (s->id == id)
		{
			flag = true;
		}
		s = s->next;
	}
	return flag;
}


void single_llist::searchInfo(int id)
{
	int value, pos = 0;
	bool flag = false;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	struct node *s;
	s = start;
	int month = 0;
	int day = 0;
	int year = 0;
	cout << "Employee's information: \n";
	while (s != NULL)
	{
		if (s->id == id)
		{
			month = stoi(s->date.substr(0, 2));
			day = stoi(s->date.substr(3, 2));
			year = stoi(s->date.substr(6));
			string date = convertDate(month, day, year);
			cout << "ID: " << s->id << "\n";
			cout << "Name: " << s->firstName << " " << s->lastName << "\n";
			cout << "SSN: " << s->SSN << "\n";
			cout << "Wage: " << "$" << s->wage << "/hr\n";
			cout << "Department: " << s->department << "\n";
			cout << "Date Hire: " << date << "\n";
		}
		s = s->next;
	}

}


void single_llist::savetoFile(string filename)
{
	ofstream outfile;
	outfile.open(filename);
	struct node *temp;
	temp = start;
	while (temp != NULL)
	{
		outfile << temp->id << " " << temp->firstName << " " << temp->lastName << " " << temp->SSN << " " << temp->wage << " " << temp->department << "  " << temp->date << "\n";
		temp = temp->next;
	}


}

/*
* Display Elements of a link list
*/
void single_llist::display()
{
	struct node *temp;
	if (start == NULL)
	{
		cout << "The List is Empty" << endl;
		return;
	}
	temp = start;
	cout << "ID\tEmployee Name    SSN     Wage      Department   Hired Date\n";
	cout << "==\t=============    ===     ====      ==========   ==========\n";
	int size = 0;
	string date;
	int month = 0;
	int day = 0;
	int year = 0;
	while (temp != NULL)
	{
		month = stoi(temp->date.substr(0, 2));
		day = stoi(temp->date.substr(3, 2));
		year = stoi(temp->date.substr(6));
		date = convertDate(month, day, year);
		cout << temp->id << "\t" << temp->firstName << " " << temp->lastName << "\t" << temp->SSN << "\t" << temp->wage << "\t" << temp->department << "  " << date << "\n";
		temp = temp->next;
		size++;
	}
	cout << "\nNumber of records in the list: " << size << "\n\n";
}

/*#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

class LinkedList
{
private:
struct Node
{
string name;
int number;
struct Node *next;
};
Node *head;

public:
LinkedList()
{
head = NULL;
}
void addLast(string, int);
void Insert(string, int);
void Delete(string, int);
void Display() const; //ABHI: What is the need to put const??
};

void LinkedList::addLast(string data1, int data2)
{
Node *newNode;
Node *nodePtr;

newNode = new Node;
newNode->name = data1;
newNode->number = data2;
newNode->next = NULL;

if (!head)
head = newNode;
else
{
nodePtr = head;
while (nodePtr->next)
nodePtr = nodePtr->next;
nodePtr->next = newNode;
}
}
void LinkedList::Insert(string data1, int data2)
{
int comp;
Node *newNode;
Node *nodePtr;
Node *prevNode = NULL;

newNode = new Node;
newNode->name = data1;
newNode->number = data2;

if (!head)
{
head = newNode;
newNode->next = NULL;
}
else
{
nodePtr = head;
prevNode = NULL;

while ((nodePtr != NULL) && (nodePtr->name.compare(data1) < 0))
//ABHI: Should not it be nodePtr->next??
{
prevNode = nodePtr;
nodePtr = nodePtr->next;
}

if (prevNode == NULL)
{
head = newNode;
newNode->next = nodePtr;
}
else
{
prevNode->next = newNode;
newNode->next = nodePtr;
}
}
}
void LinkedList::Delete(string data1, int data2)
//ABHI:What is the purpose of data2??
{
int comp;
Node *nodePtr = NULL;
Node *prevNode = NULL;
//ABHI:Assigned both the pointers to NULL.

if (!head)
return;

//ABHI:nodePtr has not been assigned to any location.
//ABHI:How it can be directly used??
if (nodePtr->name.compare(data1) == 0)
{
nodePtr = head->next;
delete head;
head = nodePtr;
}
else
{
nodePtr = head;
//ABHI:Same comment here. It should be nodePtr->next.
while ((nodePtr != NULL) && (nodePtr->name.compare(data1) != 0))
{
prevNode = nodePtr;
nodePtr = nodePtr->next;
}

if (nodePtr)
{
prevNode->next = nodePtr->next;
delete nodePtr;
}
}
}

void LinkedList::Display() const
{
Node *nodePtr;
nodePtr = head;

while (nodePtr)
{
cout << nodePtr->name << nodePtr->number << endl;
nodePtr = nodePtr->next;
}
}
int main()
{
ifstream inFile;
const int SIZE = 51;
string nm, info[SIZE], num;// input, num;
string input;
char ch;
int i = 0;
LinkedList list;
inFile.open("data.txt");
if (!inFile)
{
cout << "Error! File cannot open." << endl;
return 0;
}
else
cout << "File has been opened." << endl;

getline(inFile, input);


while (!inFile.eof())
{
if (input == "%INSERT")
{
while (
(input != "%DELETE") && (input != "%SEARCH") && (input != "%PRINT") && (input != "%END")
)
//ABHI: input is not getting changed. It is constant. Hence the trouble.
//ABHI: only nm and num are getting changed. So there should be a switch
//ABHI: case statement.
{
getline(inFile, input);
cout << input << endl;
list.Insert(input, 0);
}
continue;
}
else if (input == "%DELETE")
{
cout << "delete" << endl;
list.Delete()
}
else if (input == "%SEARCH")
{
cout << "search" << endl;
}
else if (input == "%PRINT")
cout << "print" << endl;
list.Display();

else if (input == "%END")
return 0;
getline(inFile, input);
}
}

/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <string>
using namespace std;
static int id = 1000;
struct node
{
string fullName;
string SSN;
float wage;
int identificationNumber;
string department;
string dateOfHire;
struct node *next;
struct node *prev;
}*start;

class Employee
{
public:
node* create_node(string fullName, string SSN, float wage, int identificationNumber, string department, string dateOfHire);
void insert_pos();
void delete_pos();
void search();
void update();
void display();
Employee()
{
start = NULL;
}
};

int main()
{

int choice, nodes, element, position, i;
Employee e;
start = NULL;
while (1)
{
cout << endl << "---------------------------------" << endl;
cout << endl << "Employee Management System" << endl;
cout << endl << "---------------------------------" << endl;
cout << "1.Add a new employee" << endl;
cout << "2.Search an employee" << endl;
cout << "3.Display information for all employees" << endl;
cout << "4.Edit information of an existing employee" << endl;
cout << "5.Delete an existing employee" << endl;
cout << "6.Quit " << endl;
cout << "Enter your choice : ";
cin >> choice;
switch (choice)
{
case 1:
cout << "Add employee at a given position:" << endl;
e.insert_pos();
cout << endl;
break;
case 2:
cout << "Search employee " << endl;
e.search();
cout << endl;
break;
case 3:
cout << "Display employee details: " << endl;
e.display();
break;
case 4:
cout << "Edit employee information:" << endl;
e.update();
cout << endl;
break;
case 5:
cout << "Delete an existing employee: " << endl;
// e.delete_emp();
cout << endl;
break;
case 6:
cout << "Exiting..." << endl;
exit(1);
break;
default:
cout << "Wrong choice" << endl;
}
}
}

node *Employee::create_node(string fullName, string SSN, float wage, int identificationNumber, string department, string dateOfHire)
{
struct node *temp, *s;
temp = new(struct node);
if (temp == NULL)
{
cout << "Memory not allocated " << endl;
return 0;
}
else
{
temp->fullName = fullName;
temp->SSN = SSN;
temp->wage = wage;
temp->identificationNumber = identificationNumber;
temp->department = department;
temp->dateOfHire = dateOfHire;
temp->next = NULL;
return temp;
}
}
void Employee::insert_pos()
{
int value, pos, counter = 0;
char fullName[50];
char SSN[30];
float wage;
int identificationNumber;
char department[20];
char dateOfHire[20];

cout << "Enter the employee full name: ";
cin >> fullName;
cout << "Enter the employee SSN: ";
cin >> SSN;
cout << "Enter the employee wage: ";
cin >> wage;
identificationNumber = id + 1;
cout << "Enter the employee department: ";
cin >> department;
cout << "Enter the employee date of hire (mm/dd/yyyy): ";
cin >> dateOfHire;

struct node *temp, *s, *ptr;
temp = create_node(fullName, SSN, wage, identificationNumber, department, dateOfHire);
cout << "Enter the position at which node to be inserted: ";
cin >> pos;
int i;
s = start;
while (s != NULL)
{
s = s->next;
counter++;
}
if (pos == 1)

{
if (start == NULL)

{
start = temp;
start->next = NULL;
}
else
{
ptr = start;
start = temp;
start->next = ptr;
}
}
else if (pos > 1 && pos <= counter)
{
s = start;
for (i = 1; i < pos; i++)
{
ptr = s;
s = s->next;
}
ptr->next = temp;
temp->next = s;
}
else
{
cout << "Position out of range" << endl;
}
}
void Employee::delete_pos()
{
int identificationNumber, i;
bool found = false;
if (start == NULL)
{
cout << "Presently there is no employee" << endl;
return;
}
cout << "Enter the identification number of the employee to be deleted: ";
cin >> identificationNumber;
struct node *s, *ptr, *prev;
s = start;
while (s != NULL)
{
if (s->identificationNumber == identificationNumber) {
found = true;
break;
}
prev = s;
s = s->next;
}
if (found) {
//prev->next = s->next;
//free(s);
cout << "Employee with identification number " << identificationNumber << " is deleted" << endl;
}
else {
cout << "Employee with identification number " << identificationNumber << " is NOT found" << endl;
}

}
void Employee::update()
{
bool found = false;
int identificationNumber;
int value, pos, i, choice;
if (start == NULL)
{
cout << "Presently there is no employee" << endl;
return;
}
cout << "Enter the identification number of the employee to be deleted: ";
cin >> identificationNumber;
struct node *s, *ptr;
s = start;
while (s != NULL)
{
if (s->identificationNumber == identificationNumber) {
found = true;
break;
}
s = s->next;
}
if (found) {
cout << "Which information do you want to update about the employee?n";
cout << "1.Full Namen2.SSNn3.Wagen4.Departmentn5.Date Of HirenEnter choice: ";
cin >> choice;
string newVal;
float newWage;
cout << "Enter the new value:";
switch (choice) {
case 1:
cin >> newVal;
s->fullName = newVal;
//strcpy(s->fullName, newVal);
break;
case 2:
cin >> newVal;
s->SSN = newVal;
//strcpy(s->SSN, newVal);
break;
case 3:
cin >> newWage;
s->wage = newWage;
break;
case 4:
cin >> newVal;
s->department = newVal;
//strcpy(s->department, newVal);
break;
case 5:
cin >> newVal;
s->dateOfHire = newVal;
//strcpy(s->dateOfHire, newVal);
break;
}
cout << "Employee with identification number " << identificationNumber << " is deleted" << endl;
}
else {
cout << "Employee with identification number " << identificationNumber << " is NOT found" << endl;
}
}
void Employee::search()
{
int identificationNumber = 0;
int value, pos = 0;
bool found = false;
if (start == NULL)
{
cout << "Presently there is no employee" << endl;
return;
}
cout << "Enter the identification number of the employee to be deleted: ";
cin >> identificationNumber;
struct node *s;
s = start;
while (s != NULL)
{
pos++;
if (s->identificationNumber == identificationNumber) {
found = true;
break;
}
s = s->next;
}
if (found) {
cout << "Employee with identification number " << identificationNumber << " is found at position " << pos << endl;
}
else {
cout << "Employee with identification number " << identificationNumber << " is NOT found" << endl;
}
}
void Employee::display()
{
struct node *temp;
if (start == NULL)
{
cout << "Presently there is no employee" << endl;
return;
}
temp = start;
cout << "Full NametSSNtWagetDepartmentDate of Hire" << endl;
while (temp != NULL)
{
cout << temp->fullName << "t" << temp->SSN << "t" << temp->wage <<"t" << temp->department << "t" << temp->dateOfHire << "n";
temp = temp->next;
}
}

*/