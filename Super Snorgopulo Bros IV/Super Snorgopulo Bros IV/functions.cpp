
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void dialogue1()
{
	int userchoice;
	cout << "adventurer, quickly! i need a positive number, it's extremely important that you give me a postive number, the fate of the world is at stake." << endl << endl; 
	cin >> userchoice;

	while(userchoice < 0)
	{
		cout << "you fool, have you no concern for even your own well being? i said provide me with a positive number!" << endl << endl;
		cin >> userchoice;
	}

	if(userchoice > 0)
	{
		cout << "thank you traveller, you don't even know how much good you've done!" << endl << endl;
	}

	if (userchoice == 0)
	{
		cout << "you must like playing with the devil huh? you saved the world but only just barely, take care to not toy with such serious situations next time..." << endl << endl;
	}

}


void choice1()
{
	int choice = 0;
	int respawnTimer = 21;

	do
	{
		respawnTimer--;
		if (respawnTimer < 0)
		{
			cout << "ayo bruh you wanna respawn?" << endl;
			cout << "1 for yes, 2 for no." << endl;
			if (choice != 1)
			{
				cin >> choice;
			};


		}
	}

	while (choice != 1);

	cout << "a'ight cuh" << endl;

}

void countdown()
{
	int userChoice;
	cout << "This is a robbery! Give me a number now!" << endl << endl; 
	cin >> userChoice;

	while(userChoice > 1)
	{
		userChoice = userChoice - 1;
		cout << userChoice << endl;
	}

	if(userChoice <= 1)
	{
		cout << "**A minecraft creeper has appeared!**" << endl << endl;
	}


}

void arrayTest()
{
	int array[5] = {1, 2, 3, 4, 5};

	array[0] = 10;
	array[4] = 50;

	cout << "The first number in the array is " << array[0] << "." << endl << endl;
	cout << "The last number in the array is " << array[4] << "." << endl << endl;
}

void arrayTest2()
{
	const int max_size = 4;
	int array[max_size] = { 5, 10, 15, 20};

	cout << "The second number in the array is " << array[1] << "." << endl << endl;
	cout << "The size of the array is " << max_size << "." << endl << endl;
}

void arrayTest3()
{
	const int max_size = 3;
	int array[max_size] = {7, 14, 21};


	for(int i=0; i < max_size; i++)
	{
		cout << array[i];

		if(i < max_size - 1)
		{
			cout << ", ";
		}
	}
}

void constantTest()
{
	const int PLAYER_LIVES = 3;
	const string GAME_TITLE = "Adventure Quest III";


	cout << "Welcome to " << GAME_TITLE << ", You have " << PLAYER_LIVES << " lifes." << endl << endl; 

	//PLAYER_LIVES = 2;
}

void playerName()
{
	const int PLAYER_LIVES = 3;
	const string PLAYER_NAME = "Hero";

	cout << PLAYER_NAME << endl << endl; 

	cout << PLAYER_NAME.length() << endl << endl;

	cout << PLAYER_NAME[0] << endl << endl;

	//PLAYER_LIVES = 2;
}

string printLine(string text)
{
	cout << text << endl << endl;
	return "";
}


int getStringLength(string text)
{
	int stringLength = text.length();

	return stringLength;
}

bool isStringEqual(string txt_1, string txt_2)
{
	for (int i = 0; i <= getStringLength(txt_1) and i <= getStringLength(txt_2); i++  )
	{

		if(txt_1[i] == txt_2[i])
		{
			if (i == getStringLength(txt_1) and i == getStringLength(txt_2))
			{
				cout << "yes they be equal son";
				return true;
			}
		}
		else
		{
			cout << "no they do not be equal son";
			return false;
			break;
		}
	}
}

string convertToCAPS(string txt)
{

	for (int i = 0; i < txt.length(); i++)
	{
		txt[i] = toupper(txt[i]);
	}
	cout << txt << endl << endl;
	return "";
}

string convertTolower(string txt)
{

	for (int i = 0; i < txt.length(); i++)
	{
		txt[i] = tolower(txt[i]);
	}
	cout << txt << endl << endl;
	return "";
}

void welcomePlayer(string name)
{
	const int MAX_PLAYERS = 4;
	const float VERSION = 1.0;
	const string GAME_NAME = "Adventure";
	const string USERNAME = name;

	cout << "Welcome to " << GAME_NAME << " " << USERNAME << "." << endl << endl;
	cout << "Version:" << VERSION << endl; 
	cout << "MAX PLAYERS: " << MAX_PLAYERS << endl;
}

void userCommand(string userCommand)
{
	cout << "Enter a command (Type 'quit' to exit)";
	getline(cin, userCommand); 

	cout << userCommand.length() << endl << endl;

	cout << convertTolower("apple teeth") << endl << endl;

}

void pointy()
{
	int number = 42;
	int* number_ptr = &number;

	cout << number << endl;
	cout << *number_ptr << endl;
}

void maxhealth()
{
	int health = 100;
	int max_health = 150;
	int* health_ptr;

	health_ptr = &health;
	cout << "Your health is: " << *health_ptr << endl << endl;
	health_ptr = &max_health;
	cout << "Your MAX health is: " << *health_ptr << endl << endl;

	cout << health << endl << endl;

	cout << max_health<< endl << endl;


}
void nulltest(int* input)
{

	if(input == nullptr)
	{
		cout << "Is Null." << endl;
	}
	else
	{
		cout << "Is Not Null." << endl;
	}
}

void reftest()
{
	int num = 25;

	int& ref = num;

	ref = 50;

	cout << num;
}

void doubleValue(int& num)
{
	cout << num * 2;
}

void printValue(const int& num)
{
	cout << num;

	//num = 9 + 10; //should return 21
}

void writeToFile()
{
	ofstream logFile("gorpy-norpys.txt");

	if (logFile.is_open())
	{
		logFile << "gorpy norpy" << endl;
		logFile.close();
		cout << "norpy has been gorped";
	}
	else
	{
		cout << "it error, sorry bro :(";
	}
}

void score()
{
	ofstream logFile("score.txt");

	if (logFile.is_open())
	{
		logFile << "100" << endl;
		logFile.close();
		cout << "u got a score" << endl << endl;
	}
	else
	{
		cout << "it error, sorry bro :(";
	}
}

void readScore()
{
	ifstream file("score.txt");
	string line;

	if(file.is_open())
	{
		while(getline(file, line))
		{
			cout << "Score:" << line << endl;
		}
		file.close();
	}
}

void log(string name, string text)
{
	ofstream logFile(name);

	if (logFile.is_open())
	{
		logFile << text << endl << endl;
		logFile.close();
		cout << "Logged!" << endl << endl;
	}
	else
	{
		cout << "it error, sorry bro :(";
	}
}

void smallGame()
{
	string playerChoice;

	cout << "You are in the woods, you needed to get a little lumber for your fire back at home, the winter is deadly, and hypothermia isn't something to play with." << endl << endl;
	cout << "But suddenly, you hear something..." << endl << endl;
	cout << "What would you like to do? (type the word to select.)" << endl << endl;

	cout << "1. Investigate." << endl << endl;
	cout << "2. Ignore it." << endl << endl;
	cout << "3. Sneak away." << endl << endl;
	cout << "4. Run away." << endl << endl;
	getline(cin, playerChoice);

	if (playerChoice == "Investigate" or playerChoice == "investigate" or playerChoice == "1")
	{
		cout << endl;
		cout << "you died." << endl << endl;
		log("choice.txt", "Investigated. (your dumb)");
	}
	else if (playerChoice == "Ignore it" or playerChoice == "ignore it" or playerChoice == "2")
	{
		cout << endl;
		cout << "you died." << endl << endl;
		log("choice.txt", "Ignored.");
	}
	else if (playerChoice == "Sneak away" or playerChoice == "sneak away" or playerChoice == "3")
	{
		cout << endl;
		cout << "you survive with injuries." << endl << endl;
		log("choice.txt", "Sneaked away.");
	}
	else if (playerChoice == "Run away" or playerChoice == "run away" or playerChoice == "4")
	{
		cout << endl;
		cout << "you survive." << endl << endl;
		log("choice.txt", "Ran away.");
	}
	else
	{
		cout << endl << endl;
		cout << "Thats not an answer." << endl << endl;
		log("choice.txt", "Invalid response.");
	}
}

void throwandcatch()
{
	const int weaponCount = 3;
	int weaponChoice;
	string arr[weaponCount] = { "gun", "big freaking gun", "twig" };

	cout << "What weapon would you to select? (type the number to select.)" << endl << endl;

	cout << "1. a gun." << endl << endl;
	cout << "2. a big [REDACTED] gun." << endl << endl;
	cout << "3. a literal stick." << endl << endl;
	cin >> weaponChoice;
	try
	{
		if (weaponChoice < 0 or weaponChoice > weaponCount or cin.fail())
		{
			throw runtime_error("Invalid Weapon Dude, YOU SUCK");
		}
	}

	catch (runtime_error)
	{
		cout << endl;
		cout << "That's not an option" << endl << endl;
		cout << "try again, input 1, 2, or 3." << endl << endl;
	}

	if (weaponChoice == 1)
	{
		cout << endl;
		cout << "cool you have a gun" << endl << endl;
	}
	else if (weaponChoice == 2)
	{
		cout << endl;
		cout << "cool you have a big [REDACTED] gun" << endl << endl;
	}
	else if (weaponChoice == 3)
	{
		cout << endl;
		cout << "cool you have a stick, you made the right choice." << endl << endl;
	}
}

int XPForNextLevel(float level)
{
	const float multiplier = 1.5;
	float neededXP;

	neededXP = pow(level, multiplier);
}

bool levelUP(float currentXP)
{
	if(currentXP >= XPForNextLevel(currentXP))
	{
		return 1;
	}
}

void displayStats(float currentXP)
{
	cout << "XP until next level: " << currentXP << "/" << XPForNextLevel(currentXP);
}