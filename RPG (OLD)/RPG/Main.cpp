#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int choice;

int main()
{
	//Player player = Player::Player();


	// Returns the length of the word "Apple".
	cout << Custom_String::Length("Apple") << endl << endl;

	// Returns the 5th character in the word "Apple".
	cout << Custom_String::CharacterAt("Apple", 5) << endl << endl;

	// Returns the true if the two strings are the same, or false if otherwise.
	cout << Custom_String::EqualTo("Apple", "Apple") << endl << endl;

}