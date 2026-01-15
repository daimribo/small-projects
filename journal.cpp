#include <iostream>
#include <fstream>
#include <string>
#define password "test123"
#define cancel(x) x == ""
using namespace std;

fstream entry("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entries.txt", fstream::app);
fstream editing("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entries.txt");
fstream key("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entry_key.txt", fstream::app);
fstream key_read("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entry_key.txt");
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
string entry_part(int decide) 
{
	system("CLS");
	string note;
	cout << "to cancel, enter" << endl;
	if(decide == 2)
		cout << "begin your entry:" << endl;
	else
		cout << "Create a title for the new entry" << endl;
	getline(cin, note);
	return note;
}
void helper() 
{
	int choice = menu();
	system("CLS");
	if (choice == 1)
	{
		cin.ignore();
		string title = entry_part(1);
		string note = entry_part(2);
		if (cancel(title))
		{
			helper();
		}
		else if (cancel(note))
		{
			helper();
		}
		if (note != "" || title != "")
		{
			entry << title << endl;
			key << title << endl;
			entry << note << endl;
		}
		note.clear();
		title.clear();
	}
	else if (choice == 2) 
	{
		string user_choice;
		string lines = "";
		cout << "Your previous entries:" << endl;
		while (getline(key_read, lines)) 
		{
			cout << lines << endl;
		}
		cout << "enter entry name to read" << endl;
		cin >> user_choice;
		lines = "";
		int parts = 0;
		string response;
		system("CLS");
		while (getline(editing, lines)) 
		{
			parts;
			if (lines == user_choice)
			{
				cout << "to return, enter" << endl;
				cout << lines << endl;
				parts++;
			}
			else if (parts == 1)
			{
				cout << lines << endl;
				cin.ignore();
				getline(cin, response);
				if (cancel(response))
					helper();
			}
		}
	}
}
int main()
{
	string passcode;
	while (passcode != password)
	{
		passcode = login();
	}
	while (true)
	{
		helper();
	}
}