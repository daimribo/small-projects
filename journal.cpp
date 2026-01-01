#include <iostream>
#include <fstream>
#define password "test123";
using namespace std;

fstream file("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\entries.txt", fstream::app);
void menu() 
{
	cout << "                                   " << endl;
	cout << "*____________ JOURNAL ____________*" << endl;
	cout << "|                                 |" << endl;
	cout << "|          [1]NEW ENTRY           |" << endl;
	cout << "|          [2]READ ENTRY          |" << endl;
}
int main()
{
	file << "gay boy ja ja ja";
	menu();
}