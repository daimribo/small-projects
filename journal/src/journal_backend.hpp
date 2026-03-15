#pragma once

#include <vector>
#include <string>

using namespace std;
string decryption(string text, int code);
vector<string> getTitles();
pair<string, string> getFullEntry(string entry_title);
void writeNewEntryIntoFile(const string& title, const string& note);
int Find_Position(string input);
int Get_Encryption_Key(int position);