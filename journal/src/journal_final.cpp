#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "journal_backend.hpp"
#define password "test123"
#define notcancel(x) x != ""
using namespace std;
enum MENU_ACTION {new_entry = 1, read_entry, edit_entry};
string login() 
{
	system("CLS");
	string input;
	cout << "                                   " << endl;
	cout << "*____________ LOG  IN ____________*" << endl;
	cout << "                                   " << endl;
	cout << "       PASSWORD: ";
	cin >> input;
	return input;
}

MENU_ACTION menu()
{
	int input;
	system("CLS");
	cout << "                                   " << endl;
	cout << "*____________ JOURNAL ____________*" << endl;
	cout << "|                                 |" << endl;
	cout << "|          [1]NEW ENTRY           |" << endl;
	cout << "|          [2]READ ENTRY          |" << endl;
	cout << "|          [3]EDIT ENTRY          |" << endl;
	cin >> input;
	return static_cast<MENU_ACTION>(input); 
}

string getUserInputWithCancel(string userPrompt) {
	//writing into entry and key
	system("CLS");
	string line;
	cout << "to cancel, enter" << endl;
	cout << userPrompt << endl;
	getline(cin, line);
	return line;
}

string getEntryText() 
{
	return getUserInputWithCancel("begin your entry:");
}

string getEntryTitle()
{
	cin.ignore();
	return getUserInputWithCancel("Create a title for the new entry");
}
void printTitles(vector<string> title_list) 
{
	system("CLS");
	int pos = 0;
	cout << "Your previous entries:" << endl;
	for (string title : title_list)
		{ 
			pos++;
			cout <<pos<<" "<< title << endl;
		}
}
void printEntry(const string title, const string entry) 
{
	system("CLS");
	string input;
	cout << title << endl;
	cout << entry << endl;
	getline(cin, input);
}
void createNewEntry() 
{
	string title = getEntryTitle();
	if (notcancel(title))
	{
		string note = getEntryText();
		if (notcancel(note))
			writeNewEntryIntoFile(title, note);
	}
}
void readEntry() 
{
	int user_choice;
	printTitles(getTitles());
	cout << "enter entry number to read" << endl;
	cin.ignore();
	cin >> user_choice;
	auto entry_parts = getFullEntry(user_choice);
	printEntry(entry_parts.first, entry_parts.second);
}
void handleMenuActions(MENU_ACTION choice) 
{	
	if (choice == new_entry)
	{
		createNewEntry();
	}
	else if (choice == read_entry)
	{
		readEntry();
	}
	/*else if(choice == edit_entry)
	{
		
	}*/
}
int main()
{
	string passcode;
	while (passcode != password)
	{
		passcode = login();
	}
	handleMenuActions(menu()); 
}