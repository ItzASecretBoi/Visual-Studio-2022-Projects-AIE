#include <iostream>
#include <string>
#include <fstream>
#include "Def.h"

#ifndef  DEF_H
#define DEF_H
using namespace std;

//string class constructor
Custom_String::Custom_String()
{
	testString_1 = "Apple";
	testString_2 = "Bannana";
	testString_3 = "Peach";
	cout << "Constructor Called, default strings made..." << endl << endl;
	cout << testString_1 << endl << endl;
	cout << testString_2 << endl << endl;
	cout << testString_3 << endl << endl;
}

//
int Custom_String::Length(string str)
{
	return str.length();
}

char Custom_String::CharacterAt(string str, int index)
{
	return str[index - 1];
}

bool Custom_String::EqualTo(string str_1, string str_2)
{
	if (str_1 == str_2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Custom_String::Append(string str_1, string str_2)
{
	return str_1 + str_2;
}

string Custom_String::Prepend(string str_1, string str_2)
{
	return str_2 + str_1;
}

string Custom_String::ToLower(string txt)
{

	for (int i = 0; i < txt.length(); i++)
	{
		txt[i] = tolower(txt[i]);
	}

	return txt;
}

string Custom_String::ToUpper(string txt)
{

	for (int i = 0; i < txt.length(); i++)
	{
		txt[i] = toupper(txt[i]);
	}
	return txt;
}


 bool Custom_String::Find(string input, string find)
 {
	
	 int position = input.find(find);

		 if(position != string::npos)
		 {
			 return true;
		 }
		 else
		 {
			 return false;
		 }
 }

 bool Custom_String::Find(string input, string find, int skip)
 {


	 int position = input.find(find, skip);

	 if (position != string::npos)
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
 }

 string Custom_String::Replace(string sentence,string toReplace, string replace)
 {

	 int sentence_start = 0;

	 while ((sentence_start = sentence.find(toReplace, sentence_start)) != string::npos)
	 {
		 sentence.replace(sentence_start, toReplace.length(), replace);
		 sentence_start += replace.length();
	 }
	 return sentence;
 }

 string Custom_String::ReadFromConsole()
 {
	 string gorpy_norpy = "ImaginePuttingAPlaceholderHere";
	 cout << "Waiting for input..." << endl << endl;
	 getline(cin, gorpy_norpy);
	 return gorpy_norpy;
 }

 string Custom_String::WriteToConsole(string str)
 {
	 cout << str << endl;
	 return str;
 }



 bool Custom_String::test_Length()
 { 
	 testString_1;

	 if(Length(testString_1) == testString_1.length())
	 {
		 cout << "Length() Function: Passed" << endl << endl;
		 return true;
	 }
	 else
	 {
		 cout << "Length Function: Failed" << endl << endl;
		 return false;
	 }
 }

 bool Custom_String::test_CharacterAt()
{
	 int skip = 1;

	 if((CharacterAt(testString_1, skip) == testString_1[skip-1]))
	 {
		 cout << "CharacterAt() Function: Passed" << endl << endl;
		 return true;
	 }
	 else
	 {
		 cout << "CharacterAt() Function: Failed" << endl << endl;
		 return false;
	 }
}

 bool Custom_String::test_EqualTo()
{
	 if(EqualTo(testString_1, testString_1) == true and EqualTo(testString_1, testString_2) == false)
	 {
		 cout << "EqualTo() Function: Passed" << endl << endl;
		 return true;
	 }
	 else
	 {
		 cout << "EqualTo() Function: Failed" << endl << endl;
		 return false;
	 }
}

 bool Custom_String::test_Append()
{
	 if(Append(testString_1, testString_2) == (testString_1 + testString_2))
	 {
		 cout << "Append() Function: Passed" << endl << endl;
		 return true;
	 }
	 else
	 {
		 cout << "Append() Function: Failed" << endl << endl;
		 return false;
	 }
}

 bool Custom_String::test_Prepend()
{
	 if (Prepend(testString_1, testString_2) == (testString_2 + testString_1))
	 {
		 cout << "Prepend() Function: Passed" << endl << endl;
		 return true;
	 }
	 else
	 {
		 cout << "Prepend() Function: Failed" << endl << endl;
		 return false;
	 }
}

//
  bool Custom_String::test_ToLower()
 {
	  string final_string = testString_1;

	  for (int i = 0; i < testString_1.length(); i++)
	  {
		  final_string[i] = tolower(testString_1[i]);
	  }

	  if (ToLower(testString_1) == final_string)
	  {
		  cout << "ToLower() Function: Passed" << endl << endl;
		  return true;
	  }
	  else
	  {
		  cout << "ToLower() Function: Failed" << endl << endl;
		  return false;
	  }
 }

   bool Custom_String::test_ToUpper()
  {
	  string final_string = testString_1;

	  for (int i = 0; i < testString_1.length(); i++)
	  {
		  final_string[i] = toupper(testString_1[i]);
	  }

	  if (ToUpper(testString_1) == final_string)
	  {
		  cout << "ToUpper() Function: Passed" << endl << endl;
		  return true;
	  }
	  else
	  {
		  cout << "ToUpper() Function: Failed" << endl << endl;
		  return false;
	  }
  }

//
   bool Custom_String::test_Find()
  {
	   if (Find(testString_1, testString_1) != string::npos)
	   {
		   cout << "Find() Function: Passed" << endl << endl;
		   return true;
	   }
	   else
	   {
		   cout << "Find() Function: Failed" << endl << endl;
		   return false;
	   }
  }

 bool Custom_String::test_ReadFromConsole()
{
	 //Here I'm checking if the placeholder text is still there or not, 
	 // if it isn't clearly the input worked & changed the variable. 

	 // (Unless the input you put in was the placeholder text of course, but uh.)
	 // I couldn't really think of a better way to do this the func litterally
	 // just takes an input.

	 if(ReadFromConsole() != "ImaginePuttingAPlaceholderHere")
	 {
		 cout << "ReadFromConsole() Function: Passed" << endl << endl;
		 return true;
	 }
	 else
	 {
		 cout << "ReadFromConsole() Function: Failed" << endl << endl;
		 return false;
	 }
}

 bool Custom_String::test_WriteToConsole()
{

	 if (WriteToConsole(testString_1) == testString_1)
	 {
		 cout << "WriteToConsole() Function: Passed" << endl << endl;
		 return true;
	 }
	 else
	 {
		 cout << "WriteToConsole() Function: Failed" << endl << endl;
		 return false;
	 }

}

 bool Custom_String::test_Replace()
 {

	 if (Replace(testString_1, testString_1, testString_2) == testString_2)
	 {
		 cout << "Replace() Function: Passed" << endl << endl;
		 return true;
	 }
	 else
	 {
		 cout << "Replace() Function: Failed" << endl << endl;
		 return false;
	 }

 }

 bool Custom_String::test_All()
 {

	int TotalTests = 11;

	bool LengthTest = test_Length();

	bool CharacterAtTest = test_CharacterAt();

	bool EqualToTest = test_EqualTo();

	bool AppendTest = test_Append();

	bool PrependTest = test_Prepend();

	bool ToLowerTest = test_ToLower();

	bool ToUpperTest = test_ToUpper();

	bool WriteToConsoleTest = test_WriteToConsole();

	bool ReplaceTest = test_Replace();

	bool FindTest = test_Find();

	bool ReadFromConsoleTest = test_ReadFromConsole();

	int PassedTests = LengthTest + CharacterAtTest + EqualToTest + AppendTest + PrependTest + ToLowerTest + ToUpperTest + FindTest + ReadFromConsoleTest + WriteToConsoleTest + ReplaceTest;

	float PassedPercentage = PassedTests * 100 / TotalTests;

	cout << PassedPercentage << + "%" << + " Passed!" << endl << endl;

	if(PassedPercentage == 100)
	{

		ofstream logFile("String_Class_Test.txt");

		if(logFile.is_open())
		{
			logFile <<__DATE__ << endl;
			logFile <<__TIME__ << endl << endl;

			logFile << "Percentage Of Tests Passed: " << PassedPercentage << + "%" << endl << endl;
			logFile << "LengthTest Passed?: " << LengthTest << endl << endl;
			logFile << "CharacterAtTest Passed?: " << CharacterAtTest << endl << endl;
			logFile << "EqualToTest Passed?: " << EqualToTest << endl << endl;
			logFile << "PrependTest Passed?: " << PrependTest << endl << endl;
			logFile << "AppendTest Passed?: " << AppendTest << endl << endl;
			logFile << "ToLowerTest Passed?: " << ToLowerTest << endl << endl;
			logFile << "ToUpperTest Passed?: " << ToUpperTest << endl << endl;
			logFile << "ReadFromConsoleTest Passed?: " << ReadFromConsoleTest << endl << endl;
			logFile << "WriteToConsoleTest Passed?: " << WriteToConsoleTest << endl << endl;
			logFile << "ReplaceTest Passed?: " << ReplaceTest << endl << endl;
			logFile << "FindTest Passed?: " << FindTest << endl << endl;

			cout << "Test Log Saved As 'String_Class_Test.txt'!" << endl << endl;
		}
		
		return true;
	}
	else
	{
		return false;
	}

 }


#endif;

