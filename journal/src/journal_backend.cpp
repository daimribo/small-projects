#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
fstream entry_file("entries.txt", fstream::app);
fstream key("keys.txt", fstream::app);
fstream entry_key("entry_titles.txt", fstream::app);

pair<string,int> encrypt(string text)
{
	int key = rand();
	for(auto &letter : text)
		letter = (letter+key);
	return make_pair(text,key);
}
string decryption(string text, int code)
{
	for(auto &letter : text)
		letter = (letter-code);
	return text;
}
/*int Index_Entries()
{
	string line;
	ifstream read_titles("entry_titles.txt");
	int index = 1;
	while(read_titles >> line)
		index++;
	return index;
}*/
int Get_Encryption_Key(int position)
{
	int line =0;
	int turn = 0;
	ifstream key_read("keys.txt");
	while(key_read>>line)
	{
		turn++;
		if(turn == position)
			return line;
	}
	return 0;
}
vector<string> getTitles()
{
	int key_location = -1;
	vector<string> titles;
	fstream entry_key_read("entry_titles.txt");
	for (string line; getline(entry_key_read, line);)
	{
		key_location+= 2;
		titles.push_back(decryption(line,Get_Encryption_Key(key_location)));
	}
	return titles;
}
pair<string, string> getFullEntry(int title_position)
{
	cin.ignore();
	string lines;
	string title;
	string entry;
	double title_turn = 0.5;
	int key_turn = 0;
	fstream editing("entries.txt");
	while (getline(editing, lines))
	{
		key_turn ++;
		title_turn += 0.5;
		if (title_turn == title_position)
			title = decryption(lines, Get_Encryption_Key(key_turn));
		else if (title_turn == title_position + 0.5)
		{
			entry = decryption(lines, Get_Encryption_Key(ceil(key_turn)));
			break;
		}
	}
	return make_pair(title, entry);
}
void writeNewEntryIntoFile(const string& title, const string& note) 
{
	auto encryption_entry = encrypt(note);
	auto encryption_title = encrypt(title);
	entry_file << encryption_title.first << endl;
	entry_key<< encryption_title.first << endl;
	entry_file << encryption_entry.first << endl;
	key << encryption_title.second << endl;
	key << encryption_entry.second << endl;
}
