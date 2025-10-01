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


	// if health is <= 50% of it's max.
	if (health <= max_health * 50 / 100)
	{
		description = description_low_health;
	}

	// if health is <= 75% of it's max.
	else if (health <= max_health * 75 / 100)
	{
		description = description_medium_health;
	}


	// if health is >= than it's max.
	else if (health >= max_health)
	{
		description = description_normal_health;
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

void Item::Use()
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

Room::Room(string set_name, string set_description, string set_inspect, int set_north, int set_south, int set_east, int set_west)
{
	name = set_name;
	description = set_description;

	inspect = set_inspect;
	roomNorth = set_north;
	roomSouth = set_south;
	roomEast = set_east;
	roomWest = set_west;
}

Room::Room(string set_name, string set_description, string set_inspect, int set_north, int set_south, int set_east, int set_west, int set_north_locked, int set_south_locked, int set_east_locked, int set_west_locked)
{
	name = set_name;
	description = set_description;

	inspect = set_inspect;
	roomNorth = set_north;
	roomSouth = set_south;
	roomEast = set_east;
	roomWest = set_west;

	north_is_locked = set_north_locked;
	south_is_locked = set_south_locked;
	east_is_locked = set_east_locked;
	west_is_locked = set_west_locked;
}

Locations::Locations()
{
// reguarding the numbers in this constructor, remember!
// 1st postion = north
// 2nd position = south
// 3rd postition = east
// 4th position = west

// put 0 if the location is a dead end!

	rooms[0] = Room("Dead End", "I didn't really go anywhere, it was a dead end...", 0, 0, 0, 0);// The players current room should never ever be set to dead end, they will be softlocked...
	rooms[1] = Room("Bedroom", "This seems to be a bedroom? I guess someone tucked me in or something... Maybe there is something of use in here?", "Theres a bed in the corner with a glint, underneath it, I think its a key?\nAlso, the bed is covered in blood.\nBut... I just woke up from there... \n\nThis room is enclosed, but theres a door facing NORTH.\nGoing any other direction would be pointless.\n\n", 2, 0, 0, 0, 1, 0, 0, 0);
	rooms[2] = Room("Kitchen", "It seems like I'm in a kitchen.", "This kitchen is disgusting dude...\n\n",  3, 1, 0, 0, 0, 0, 0, 0);
	rooms[3] = Room("Broom Closet", "It seems like I'm in a broom closet.", 0, 2, 0, 0);
	rooms[4] = Room("Broom Closet", "It seems like I'm in a broom closet.", 0, 2, 0, 0);
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

	else if (convert.ToUpper(playerChoice) == "INSPECT")
	{

		locations.rooms[currentRoom].Inspected = true;

		cout << locations.rooms[currentRoom].inspect;

		if(currentRoom == 1 and has_bedroom_key == false)
		{
			cout << "Take the key?\n\nYes or No?: ";
			getline(cin, playerChoice); cout << endl;

			if((convert.ToUpper(playerChoice) == "YES"))
			{
				cout << "**You took the key...**\n\n";
				has_bedroom_key = true;
				locations.rooms[currentRoom].inspect = "Theres a bed in the corner that used to have a glint underneath it, The bed is covered in blood. But.. \nI just woke up from there... \n\nThis room is enclosed, but theres a door facing NORTH.\nGoing any other direction would be pointless.\n\n";
			}
			if ((convert.ToUpper(playerChoice) == "NO"))
			{
				has_bedroom_key = false;
			}
			else if((convert.ToUpper(playerChoice) != "YES") or (convert.ToUpper(playerChoice) != "NO") and has_bedroom_key == 0)
			{
				cout << "Fuck, am I stupid? I decided not to take it...\n\n";
				Choice();
			}
		}

		Choice();
	}

	else if (convert.ToUpper(playerChoice) == "INSPECT SELF")
	{
		adjustDescription();
		cout << description;

		cout << "Health: " << health << "/" << max_health << endl << endl;

		Choice();
	}

	else if (convert.ToUpper(playerChoice) == "USE")
	{

		if (currentRoom == 1 and locations.rooms[currentRoom].Inspected and has_bedroom_key)
		{
			locations.rooms[currentRoom].north_is_locked = 0;
			cout << "You use the key to unlock the door!\nFreedom, at last.\n\n";
		}
		else
		{
			cout << "I don't even have anything to use..." << endl << endl;
		}

		Choice();
	}

	else if (convert.ToUpper(playerChoice) == "EXIT" or convert.ToUpper(playerChoice) == "QUIT")
	{
	}

	//else if (convert.ToUpper(playerChoice) == "INVENTORY")
	//{
	//	for (int i = 0; i < inventory_size; i++)
	//	{
	//		cout << "Slot "<< i << ": " << inventory[i].name << endl << endl;
	//	}
	//	Choice();
	//}

	else if (convert.ToUpper(playerChoice) == "HELP")
	{
		cout << "Commands:" << endl << endl;
		cout << "go north" << endl;
		cout << "go south" << endl;
		cout << "go east" << endl;
		cout << "go west" << endl;
		cout << "inspect" << endl;
		cout << "inspect self" << endl;
		cout << "help" << endl;
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

	// 0 is dead end logic
	switch (direction)
	{

	case 1:

		if (locations.rooms[currentRoom].north_is_locked) // if the room in this direction is locked.
		{

			currentRoom = currentRoom;
			cout << "Of course, the door is locked..\nIf I have a key, I should probabally USE it." << endl << endl;
			break;
		}

		if (locations.rooms[currentRoom].roomNorth == 0) // if the room in this direction is a dead end. (It is the same for all other cases.)
		{

			currentRoom = currentRoom;
			cout << locations.rooms[0].description << endl << endl;
			break;
		}

		currentRoom = locations.rooms[currentRoom].roomNorth;
		cout << locations.rooms[currentRoom].description << endl << endl;
		break;

	case 2:

		if (locations.rooms[currentRoom].south_is_locked)
		{

			currentRoom = currentRoom;
			cout << "Of course, the door is locked..\nIf I have a key, I should probabally USE it." << endl << endl;
			break;
		}

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

		if (locations.rooms[currentRoom].east_is_locked)
		{

			currentRoom = currentRoom;
			cout << "Of course, the door is locked..\nIf I have a key, I should probabally USE it." << endl << endl;
			break;
		}

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

		if (locations.rooms[currentRoom].west_is_locked)
		{

			currentRoom = currentRoom;
			cout << "Of course, the door is locked..\nIf I have a key, I should probabally USE it." << endl << endl;
			break;
		}

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
	name = "???";
	health = 100;
	max_health = 100;
	currentRoom = 1;
	inventory_size = 6;

	description_low_health = "I don't think I'll make it much further, everything hurts...\n\n";

	description_medium_health = "I could be better, I'm a little worse for wear at the moment.\n\n";

	description_normal_health = "I think I'm okay, I don't feel too bad right now.\n\n";

	cout << name << ": \n" << "*You wake up.*" << endl << endl;

	cout << name << ": \n" << "Agh, my head is throbbing..." << endl << endl;

	cout << "*You check your surroundings.*" << endl << endl;

	cout << locations.rooms[currentRoom].description << endl << endl;

	cout << name << ": \n" << "What type of netflix original shit is this?" << endl << endl;

	cout << "*You think to yourself...*" << endl << endl;

	cout << name << ": \n" << "I can't even remember my name... I think my name was.. uhh.\nEnter your name: " ;

	getline(cin, name); cout << endl;

	cout << name << ": \n" << "Oh right! I'm " << name << ".\nI can't believe I almost forgot that...\n\n";

	cout << "Commands:" << endl;
	cout << "go north" << endl;
	cout << "go south" << endl;
	cout << "go east" << endl;
	cout << "go west" << endl;
	cout << "inspect" << endl;
	cout << "inspect self" << endl;
	cout << "help" << endl;
	cout << "exit" << endl << endl;

	Choice();
}



#endif;