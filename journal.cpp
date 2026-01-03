#include <iostream>
#include <fstream>
#include <string>
#define password "test123"
using namespace std;

fstream entry("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entries.txt", fstream::app);
fstream editing("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entries.txt");
fstream key("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entry_key.txt", fstream::app);
string login()
{
	system("CLS");
	string enter = "";
	cout << "                                   " << endl;
	cout << "*____________ LOG  IN ____________*" << endl;
	cout << "                                   " << endl;
	cout << "       PASSWORD: ";
	cin >> enter;
	return enter;
}
int menu()
{
	system("CLS");
	int user_choice = 0;
	cout << "                                   " << endl;
	cout << "*____________ JOURNAL ____________*" << endl;
	cout << "|                                 |" << endl;
	cout << "|          [1]NEW ENTRY           |" << endl;
	cout << "|          [2]READ ENTRY          |" << endl;
	cin >> user_choice;
	return user_choice;
}
void new_entry()
{
	system("CLS");
	string write;
	cout << "to cancel enter X" << endl;
	cout << "Create a title for the new entry" << endl;
	cin.ignore();
	getline(cin, write);
	if (write == "X" || write == "x")
	{
		menu();
	}
	else
	{
		key << write << endl;
		entry << write << endl;
	}
	system("CLS");
	string note;
	cout << "to cancel enter X" << endl;
	cout << "begin your entry:" << endl;
	getline(cin, note);
	if (note == "X" || note == "x")
	{
		menu();
	}
	else
	{
		entry << note << endl;
	}
	entry << " " << endl;
}
int main()
{
	string passcode;
	while (passcode != password)
	{
		passcode = login();
	}
	int choice = menu();
	if (choice == 1)
	{
		new_entry();
	}
}