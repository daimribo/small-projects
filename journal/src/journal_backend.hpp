#pragma once

#include <vector>
#include <string>

using namespace std;
string decryption(string text, int code);
vector<string> getTitles();
pair<string, string> getFullEntry(int title_position);
void writeNewEntryIntoFile(const string& title, const string& note);
int Get_Encryption_Key(int position);