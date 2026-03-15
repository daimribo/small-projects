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
	srand(NULL);
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
int Find_Position(string input)
{
	int position = 0;
	int code = 0;
	string line;
	ifstream keys("keys.txt");
	ifstream titles("entry_title.txt");
	while(getline(titles,line))
	{
		position++;
		while(keys >> code)
		{
			if(decryption(line,code) == input)
				return position;
		}
	}
}
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
}
vector<string> getTitles()
{
	int location = 0;
	vector<string> titles;
	fstream entry_key_read("entry_titles.txt");
	for (string line; getline(entry_key_read, line); )
	{
		location++;
		titles.push_back(decryption(line,Get_Encryption_Key(location)));
	}
	return titles;
}
pair<string, string> getFullEntry(string entry_title)
{
	string lines;
	string title;
	string entry;
	int turn = 0;
	fstream editing("entries.txt");
	int parts = 0;
	while (getline(editing, lines))
	{
		turn++;
		if (lines == entry_title)
		{
			parts++;
			title = decryption(lines, Get_Encryption_Key(turn));
		}
		else if (parts == 1)
		{
			parts = 0;
			entry = decryption(lines, Get_Encryption_Key(turn));
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
	entry_key << encryption_title.first << endl;
	entry_file << encryption_entry.first << endl;
	key << encryption_title.second << endl;
	key << encryption_entry.second << endl;
}
