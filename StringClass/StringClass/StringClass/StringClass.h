#pragma once
using namespace std;

class Custom_String
{

public:

	string testString_1;
	string testString_2;
	string testString_3;

	Custom_String();

	int Length(string str);

	char CharacterAt(string str, int index);

	bool EqualTo(string str_1, string str_2);

	string Append(string str_1, string str_2);

	string Prepend(string str_1, string str_2);

	string ToLower(string str);

	string ToUpper(string str);

	bool Find(string input, string find);

	bool Find(string input, string find, int skip);

	string ReadFromConsole();

	string WriteToConsole(string str);

	string Replace(string sentence, string toReplace, string replace);

	bool test_Length();

	bool test_CharacterAt();

	bool test_EqualTo();

	bool test_Append();

	bool test_Prepend();

	bool test_ToLower();

	bool test_ToUpper();

	bool test_Find();

	bool test_ReadFromConsole();

	bool test_WriteToConsole();

	bool test_Replace();

	bool test_All();
};
