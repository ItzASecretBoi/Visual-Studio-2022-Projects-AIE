#include <iostream>
#include <string>
#include <fstream>
#include "StringClass.h"
#include "RPG.h"

#ifndef  StringClass_H
#define StringClass_H
using namespace std;

//entity funcs
Entity::Entity()
{

}

int Entity::setHealth(int newHealth)
{
	return health = newHealth;
}

int Entity::getHealth()
{
	return health;
}

int Entity::adjustHealth(int adjustment)
{
	return health += adjustment;
	adjustDescription();
}

int Entity::attack(Entity victim)
{
	return victim.adjustHealth(base_damage + level * 0.5);
}

void Entity::adjustDescription()
{
	// if health is >= than it's max.
	if (health >= max_health)
	{
		description = description_normal_health;
	}

	// if health is <= 75% of it's max.
	else if (health <= max_health * 75 / 100)
	{
		description = description_medium_health;
	}

	// if health is <= 50% of it's max.
	else if (health <= max_health * 50 / 100)
	{
		description = description_low_health;
	}

	// else function is prolly broken
	else
	{
		description = "adjustDescription() function has error, please check...";
	}

}

//item funcs

Item::Item()
{
	name = "Null";
	description = "Null";
};

void Item::use()
{

}

//room funcs


//If you ever see this! It means that you made a room, that leads to nowhere! 
// For example if you were in a kitchen & went north, and it led you here, 
// you now know that the north position for kitchen leads to nowhere, and needs
// to be fixed.
Room::Room() 
{
	name = "Backrooms";
	description = "This location is desolate of any life, it looks like an office building or something.";
	Item items[5] = {};

};

Room::Room(string set_name, string set_description, int set_north, int set_south, int set_east, int set_west)
{
	name = set_name;
	description = set_description;

	roomNorth = set_north;
	roomSouth = set_south;
	roomEast = set_east;
	roomWest = set_west;
}

Locations::Locations()
{
// reguarding the numbers in this constructor, remember!
// 1st postion = north
// 2nd position = south
// 3rd postition = east
// 4th position = west

	// put 0 if the location is a dead end!

	rooms[0] = Room("Dead End", "I didn't really go anywhere, it was a dead end...", 0, 0, 0, 0);
	rooms[1] = Room("Ruins", "It seems like I'm in some ruins.", 0, 0, 0, 2);
	rooms[2] = Room("Kitchen", "It seems like I'm in a kitchen.", 3, 1, 0, 0);
	rooms[3] = Room("Broom Closet", "It seems like I'm in a broom closet.", 0, 2, 0, 0);

};

//player funcs

void Player::Choice()
{

	cout << "What should I do?" << endl << endl;

	string playerChoice = "";
	getline(cin, playerChoice); cout << endl;
	Custom_String convert;



	if (convert.ToUpper(playerChoice) == "GO NORTH")
	{
		changeCurrentRoom(1);
		Choice();
	}

	else if (convert.ToUpper(playerChoice) == "GO SOUTH")
	{
		changeCurrentRoom(2);
		Choice();
	}

	else if (convert.ToUpper(playerChoice) == "GO EAST")
	{
		changeCurrentRoom(3);
		Choice();
	}

	else if (convert.ToUpper(playerChoice) == "GO WEST")
	{
		changeCurrentRoom(4);
		Choice();
	}

	else if (convert.ToUpper(playerChoice) == "EXIT")
	{
	}

	else if (convert.ToUpper(playerChoice) == "HELP")
	{
		cout << "Commands:" << endl << endl;
		cout << "go north" << endl;
		cout << "go south" << endl;
		cout << "go east" << endl;
		cout << "go west" << endl;
		cout << "exit" << endl << endl;

		Choice();
	}

	else
	{
		cout << "*You think to yourself*" << endl << endl;
		cout << "What am I thinking? That doesn't even make sense..." << endl << endl;
		cout << "Hint: If you need assistance with commands, use the command, 'help'." << endl << endl;
		Choice();
	}
}

void Player::changeCurrentRoom(int direction)
{
	// 1 = north
	// 2 = south
	// 3 = east
	// 4 = west

	switch (direction)
	{

	case 1:

		if (locations.rooms[currentRoom].roomNorth == 0)
		{

			currentRoom = currentRoom;
			cout << locations.rooms[0].description << endl << endl;
			break;
		}

		currentRoom = locations.rooms[currentRoom].roomNorth;
		cout << locations.rooms[currentRoom].description << endl << endl;
		break;

	case 2:

		if (locations.rooms[currentRoom].roomSouth == 0)
		{

			currentRoom = currentRoom;
			cout << locations.rooms[0].description << endl << endl;
			break;
		}

		currentRoom = locations.rooms[currentRoom].roomSouth;
		cout << locations.rooms[currentRoom].description << endl << endl;
		break;

	case 3:

		if (locations.rooms[currentRoom].roomEast == 0)
		{

			currentRoom = currentRoom;
			cout << locations.rooms[0].description << endl << endl;
			break;
		}

		currentRoom = locations.rooms[currentRoom].roomEast;
		cout << locations.rooms[currentRoom].description << endl << endl;
		break;

	case 4:

		if (locations.rooms[currentRoom].roomWest == 0)
		{

			currentRoom = currentRoom;
			cout << locations.rooms[0].description << endl << endl;
			break;
		}

		currentRoom = locations.rooms[currentRoom].roomWest;
		cout << locations.rooms[currentRoom].description << endl << endl;
		break;

	default:
		cout << "*You think to yourself*" << endl << endl;
		cout << "What am I thinking? That doesn't even make sense..." << endl << endl;
		Choice();
		break;
	}
}

Player::Player()
{
	currentRoom = 1;

	cout << "*You wake up.*" << endl << endl;

	cout << "Agh, my head is throbbing..." << endl << endl;

	cout << "*You check your surroundings.*" << endl << endl;

	cout << locations.rooms[currentRoom].description << endl << endl;

	cout << "Damn, what type of netflix original shit is this?" << endl << endl;

	cout << "*You think to yourself...*" << endl << endl;

	Choice();
}



#endif;