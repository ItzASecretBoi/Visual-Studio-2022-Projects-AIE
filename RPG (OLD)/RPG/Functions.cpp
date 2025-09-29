#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

//base funcs

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

Item::Item()
{
	name = "Null";
	description = "Null";
};

void Item::use()
{

}

Room::Room(string set_name, string set_description, Item items[5])
{
	name = set_name;
	description = set_description;
	items[5] = {};
};

Room::Room()
{
	name = "Backrooms";
	description = "This location is desolate of any life, it looks like an office building or something.";
	Item items[5] = {};
};


Player::Player()
{
	currentRoom = Room();

	cout << "*You wake up.*" << endl << endl;

	cout << "Agh, my head is throbbing..." << endl << endl;

	cout << "*You check your surroundings.*" << endl << endl;

	cout << currentRoom.description << endl << endl;


}
//Inhereted Funcs