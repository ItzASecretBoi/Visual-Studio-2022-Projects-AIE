#include <iostream>
#include <string>
#include <fstream>
#include "CustomString.h"
#include "CustomPrint.h"
#include "RPG.h"

using namespace std;

//entity funcs
Entity::Entity()
{
	nametag = name + ":\n";
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
	health += adjustment;
	adjustDescription();
	return health;
}


int Entity::attack(Entity& victim)
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

int Item::Use()
{
	return 0;
}

Bandage::Bandage()
{
	name = "Bandage";
	description = "Heals 10 HP.";
}

int Bandage::Use()
{
	return 10;
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


		//Dead End
	rooms[0].name = "Dead End";
	rooms[0].description = "I didn't really go anywhere, it was a dead end...";
	rooms[0].roomNorth = 0;
	rooms[0].roomSouth = 0;
	rooms[0].roomEast = 0;
	rooms[0].roomWest = 0;

	//Bedroom
	rooms[1].name = "Bedroom";
	rooms[1].description = "This seems to be a bedroom? I guess someone tucked me in or something... Maybe there is something of use in here?";
	rooms[1].inspect = "Theres a bed in the corner with a glint, underneath it, I think its a key?\nAlso, the bed is covered in blood.\nBut... I just woke up from there... \n\nThis room is enclosed, but theres a door facing NORTH.\nGoing any other direction would be pointless.\n\n";
	rooms[1].roomNorth = 2;
	rooms[1].roomSouth = 0;
	rooms[1].roomEast = 0;
	rooms[1].roomWest = 0;
	rooms[1].north_is_locked = true;

	//Hallway
	rooms[2].name = "Hallway.";
	rooms[2].description = "Now I'm in a hallway.";
	rooms[2].inspect = "This hallway is disgusting dude... But hey, atleast I found a bandage in a cabinet nearby!\n\n";
	rooms[2].roomNorth = 3;
	rooms[2].roomSouth = 3;
	rooms[2].roomEast = 3;
	rooms[2].roomWest = 3;
	rooms[2].room_Has_Hostile = true;
	rooms[2].room_Has_Bandage = 1;

	rooms[2].enemy.name = "Robert";
	rooms[2].enemy.xpDrop = 500;
	rooms[2].enemy.race = "Rat";
	rooms[2].enemy.description = "It's a rat.";
	rooms[2].enemy.health = 25;
	rooms[2].enemy.base_damage = 2;
	rooms[2].enemy.death_dialogue = "The grotesque rat turns into a messy morsel under your foot... ";
	rooms[2].enemy.encounter_dialogue = "Now I'm in a hallway, but.. theres a silhouette in the distance..\nI try to make it out and.. It's a Grotesque Rat! ";

	//DLC
	rooms[3].name = "Boss Room";
	rooms[3].description = "The walls in this direction are just covered in the text that say\n'ROOM INACCCESSIBLE: PREORDER DLC - ONLY 9.8MIL! BUY NOW!'.\nWhat a lazy dev dude...";
	rooms[3].roomNorth = 0;
	rooms[3].roomSouth = 0;
	rooms[3].roomEast = 0;
	rooms[3].roomWest = 0;

	rooms[3].room_Has_Hostile = true;
	rooms[3].room_Has_Bandage = 1;

	rooms[3].enemy.name = "Qwentin";
	rooms[3].enemy.race = "Human";
	rooms[3].enemy.description = "It's a loser.";
	rooms[3].enemy.health = 1;
	rooms[3].enemy.base_damage = 1;
	rooms[3].enemy.death_dialogue = "He exploded tragically killing you both, pay 3000$ USD for the rest of the lore. :)\n\n";
	rooms[3].enemy.encounter_dialogue = "Now I'm in a dark room, but.. theres a silhouette in the distance..\nI try to make it out and.. It's a Decrepid Human! ";

}

//player funcs

int Player::XPForNextLevel(float level)
{
	const float multiplier = 1.5;
	float neededXP;

	neededXP = pow(level, multiplier);
	return neededXP;
}

int Player::levelUp(float level, float currentXP)
{

	if (currentXP >= XPForNextLevel(level))
	{
		return level + 1;
	}
	else
	{
		return level;
	}

}

void Player::displayStats(float currentXP)
{
	cout << "XP until next level: " << currentXP << "/" << XPForNextLevel(currentXP) << endl << endl;
}

void Player::Choice()
{

	string playerChoice = "";
	Custom_String convert;

	while (true)
	{

		level = levelUp(level, currentXP);


		if (locations.rooms[currentRoom].enemy.health <= 0 and locations.rooms[currentRoom].room_Has_Hostile and locations.rooms[currentRoom].enemy.name == "Qwentin") // special check for if the enemy is Qwentin, if so kill the player upon his death.
		{
			locations.rooms[currentRoom].room_Has_Hostile = false;
			cout << locations.rooms[currentRoom].enemy.death_dialogue << endl << endl;
			break;
		}

		if (locations.rooms[currentRoom].enemy.health <= 0 and locations.rooms[currentRoom].room_Has_Hostile)
		{
			locations.rooms[currentRoom].room_Has_Hostile = false;
			cout << locations.rooms[currentRoom].enemy.death_dialogue << endl << endl;
			currentXP += locations.rooms[currentRoom].enemy.xpDrop;
			continue;
		}

		if (locations.rooms[currentRoom].room_Has_Hostile)
		{
			cout << "You are in combat with " << locations.rooms[currentRoom].enemy.name << "!" << endl << endl;
			cout << locations.rooms[currentRoom].enemy.name << "'s Health: " << locations.rooms[currentRoom].enemy.health << endl;
			cout << locations.rooms[currentRoom].enemy.name << "'s Race: " << locations.rooms[currentRoom].enemy.race << endl;
			cout << locations.rooms[currentRoom].enemy.name << "'s ATK: " << locations.rooms[currentRoom].enemy.base_damage << endl;
			cout << locations.rooms[currentRoom].enemy.name << "'s LVL: " << locations.rooms[currentRoom].enemy.level << endl << endl;

			cout << name << "'s HP: " << health << endl;
			cout << name << "'s RACE: " << race << endl;
			cout << name << "'s ATK: " << base_damage << endl;
			cout << name << "'s LVL: " << level << endl << endl;

			cout << "Tip: Your command set has changed! Use command 'help' to view your options" << endl;
			cout << "**You cannot move until combat has ended.**" << endl << endl;
		}

		cout << "What should I do?" << endl << endl;

		getline(cin, playerChoice); cout << endl;

		if (convert.ToUpper(playerChoice) == "GO NORTH" and (locations.rooms[currentRoom].room_Has_Hostile == false))
		{
			changeCurrentRoom(1);
			continue;
		}

		else if (convert.ToUpper(playerChoice) == "ATTACK" and (locations.rooms[currentRoom].room_Has_Hostile == true))
		{
			locations.rooms[currentRoom].enemy.adjustHealth(-base_damage);
			adjustHealth(-locations.rooms[currentRoom].enemy.base_damage);
			continue;
		}

		else if (convert.ToUpper(playerChoice) == "GO SOUTH" and (locations.rooms[currentRoom].room_Has_Hostile == false))
		{
			changeCurrentRoom(2);
			continue;
		}

		else if (convert.ToUpper(playerChoice) == "GO EAST" and (locations.rooms[currentRoom].room_Has_Hostile == false))
		{
			changeCurrentRoom(3);
			continue;
		}

		else if (convert.ToUpper(playerChoice) == "GO WEST" and (locations.rooms[currentRoom].room_Has_Hostile == false))
		{
			changeCurrentRoom(4);
			continue;
		}


		else if (convert.ToUpper(playerChoice) == "INSPECT")
		{

			locations.rooms[currentRoom].Inspected = true;

			cout << locations.rooms[currentRoom].inspect;

			if (currentRoom == 1 and has_bedroom_key == false)
			{
				cout << "Take the key?\n\nYes or No?: ";
				getline(cin, playerChoice); cout << endl;

				if ((convert.ToUpper(playerChoice) == "YES"))
				{
					cout << "**You took the key...**\n\n";
					has_bedroom_key = true;
					locations.rooms[currentRoom].inspect = "Theres a bed in the corner that used to have a glint underneath it, The bed is covered in blood. But.. \nI just woke up from there... \n\nThis room is enclosed, but theres a door facing NORTH.\nGoing any other direction would be pointless.\n\n";
					continue;
				}
				if ((convert.ToUpper(playerChoice) == "NO"))
				{
					has_bedroom_key = false;
				}
				else if ((convert.ToUpper(playerChoice) != "YES") or (convert.ToUpper(playerChoice) != "NO") and has_bedroom_key == 0)
				{
					cout << "Fudgewinkle, am I stupid? I decided not to take it...\n\n";
					continue;
				}
			}

		}


		else if (convert.ToUpper(playerChoice) == "COUNTER" and (locations.rooms[currentRoom].room_Has_Hostile == true))
		{
			locations.rooms[currentRoom].enemy.adjustHealth(-base_damage);

			int chance = rand() % 2;

			if (chance == 1)
			{
				locations.rooms[currentRoom].enemy.adjustHealth(-(base_damage * 2));
				cout << "Counter Success! (50% chance)" << endl << endl;
			}

			else
			{
				adjustHealth(-locations.rooms[currentRoom].enemy.base_damage);
				cout << "Counter Failed! (50% chance)" << endl << endl;
			}

		}

		else if (convert.ToUpper(playerChoice) == "INSPECT SELF")
		{
			adjustDescription();
			cout << description;

			cout << "Health: " << health << "/" << max_health << endl << endl;

			cout << name << "'s HP: " << health << endl;
			cout << name << "'s RACE: " << race << endl;
			cout << name << "'s ATK: " << base_damage << endl;
			cout << name << "'s LVL: " << level << endl << endl;

		}

		else if (convert.ToUpper(playerChoice) == "USE")
		{

			if (currentRoom == 1 and locations.rooms[currentRoom].Inspected and has_bedroom_key)
			{
				locations.rooms[currentRoom].north_is_locked = 0;
				cout << "You use the key to unlock the door!\nFreedom, at last.\n\n";
			}

			else if (currentRoom == 2 and locations.rooms[currentRoom].Inspected and locations.rooms[currentRoom].room_Has_Bandage)
			{
				health += locations.rooms[currentRoom].roomBandage.Use();
				locations.rooms[currentRoom].room_Has_Bandage = false;
				cout << "Bandage Used!\n\n";
				locations.rooms[currentRoom].inspect = "This hallway is disgusting dude... There was a bandage here but I used it.\n\n";
			}

			else
			{
				cout << "I don't even have anything to use..." << endl << endl;
			}
		}

		else if (convert.ToUpper(playerChoice) == "EXIT" or convert.ToUpper(playerChoice) == "QUIT")
		{
			break;
		}


		else if (convert.ToUpper(playerChoice) == "HELP" and locations.rooms[currentRoom].room_Has_Hostile)
		{
			cout << "Commands:" << endl << endl;
			cout << "attack" << endl;
			cout << "counter (50% chance)" << endl;
			cout << "inspect" << endl;
			cout << "inspect self" << endl;
			cout << "help" << endl;
			cout << "exit" << endl << endl;

		}

		else if (convert.ToUpper(playerChoice) == "HELP")
		{
			cout << "Commands:" << endl << endl;
			cout << "go north" << endl;
			cout << "go south" << endl;
			cout << "go east" << endl;
			cout << "go west" << endl;
			cout << "go use" << endl;
			cout << "inspect" << endl;
			cout << "inspect self" << endl;
			cout << "help" << endl;
			cout << "exit" << endl << endl;
		}

		else
		{
			cout << "*You think to yourself*" << endl << endl;
			cout << "What am I thinking? That doesn't even make sense..." << endl << endl;
			cout << "Hint: If you need assistance with commands, use the command, 'help'." << endl << endl;
		}
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

		if (locations.rooms[currentRoom].room_Has_Hostile != true)
		{
			cout << locations.rooms[currentRoom].description << endl << endl;
			break;
		}

		if (locations.rooms[currentRoom].room_Has_Hostile)
		{

			cout << locations.rooms[currentRoom].enemy.encounter_dialogue << endl << endl;
			break;
		}
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

		if (locations.rooms[currentRoom].room_Has_Hostile != true)
		{
			cout << locations.rooms[currentRoom].description << endl << endl;
			break;
		}

		if (locations.rooms[currentRoom].room_Has_Hostile)
		{
			currentRoom = currentRoom;
			cout << locations.rooms[currentRoom].enemy.encounter_dialogue << endl << endl;
			break;
		}
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

		if (locations.rooms[currentRoom].room_Has_Hostile != true)
		{
			cout << locations.rooms[currentRoom].description << endl << endl;
			break;
		}

		if (locations.rooms[currentRoom].room_Has_Hostile)
		{
			currentRoom = currentRoom;
			cout << locations.rooms[currentRoom].enemy.encounter_dialogue << endl << endl;
			break;
		}
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

		if (locations.rooms[currentRoom].room_Has_Hostile != true)
		{
			cout << locations.rooms[currentRoom].description << endl << endl;
			break;
		}

		if (locations.rooms[currentRoom].room_Has_Hostile)
		{
			currentRoom = currentRoom;
			cout << locations.rooms[currentRoom].enemy.encounter_dialogue << endl << endl;
			break;
		}
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
	srand(time(0));

	name = "???";
	nametag = name + ":\n";
	race = "Human";
	health = 25;
	max_health = 100;
	currentRoom = 1;
	inventory_size = 6;
	base_damage = 5;

	room_description = locations.rooms[currentRoom].description;

	CustomPrint speak;


	description_low_health = "I don't think I'll make it much further, everything hurts...\n\n";

	description_medium_health = "I could be better, I'm a little worse for wear at the moment.\n\n";

	description_normal_health = "I think I'm okay, I don't feel too bad right now.\n\n"; //apple

	speak.TypewriterPrintENDLENDL(speak.RESET + nametag + speak.FG_BRIGHT_GREEN + "*You wake up...*" + speak.RESET, 1);

	speak.Wait(1);

	speak.Clear();

	speak.Wait(1);

	speak.TypewriterPrint(nametag + speak.FG_BRIGHT_CYAN + "Agh, my head is " + speak.RESET, 20);

	speak.TypewriterPrintENDLENDL(speak.FG_BRIGHT_RED + "throbbing..." + speak.RESET, 20);

	speak.Wait(1);

	speak.TypewriterPrintENDLENDL(speak.FG_BRIGHT_GREEN + "*You check your surroundings.*" + speak.RESET, 10);

	speak.Wait(1);

	speak.Clear();

	speak.TypewriterPrintENDLENDL(nametag + speak.FG_BRIGHT_CYAN + room_description + speak.RESET, 50);

	speak.Wait(1);

	speak.Clear();

	speak.TypewriterPrintENDLENDL(nametag + speak.FG_BRIGHT_CYAN + "I can't even remember my name..." + speak.RESET, 50);

	speak.Wait(1);

	speak.TypewriterPrint(nametag + speak.FG_BRIGHT_CYAN + "I think my name was..." + speak.RESET, 80);

	speak.WaitMS(500);

	speak.TypewriterPrintENDL(speak.FG_BRIGHT_CYAN + " uhh..." + speak.RESET, 80);

	speak.TypewriterPrint(speak.FG_BRIGHT_CYAN + "Enter your name: " + speak.RESET, 20);

	getline(cin, name); cout << endl;

	speak.Clear();

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