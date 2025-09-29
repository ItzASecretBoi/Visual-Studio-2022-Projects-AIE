#pragma once
using namespace std;

class Entity
{

protected:
	// lore stuff
	string name;
	string race;
	string description;

	string description_low_health;
	string description_medium_health;
	string description_normal_health;

public:

	Entity();

	// stats
	const int max_health = 100;
	int health = 100;
	int level = 1;
	int base_damage = 1;

	// funcs
	int setHealth(int newHealth);

	int getHealth();

	int adjustHealth(int adjustment);

	int attack(Entity victim);

	void adjustDescription();
};

class Item
{
private:
	string name;
	string description;
public:
	Item();
	void use();
};

// never to be used or summoned, please use BaseRoom instead. 
// This is because this original class is incapable of leading to any other room, so the player will basically be stuck...

// Why did i do it like this?
// My idea on how to make a room system is that each room would lead to another, 
// but I can't store a room class in my room class while it's still being defined
// so instead i just made an inherited class to store the rooms since at that point
// its alr defined. :)


class Room
{

public:
	string name;
	string description;
	Item items[5];

	int roomNorth;
	int	roomSouth;
	int	roomEast;
	int roomWest;


	Room();

	Room(string set_name, string set_desctription, int set_north, int set_south, int set_east, int set_west);

};

class Locations : public Room
{
public:

	Locations();

	Room rooms[5];
};

class Player : public Entity
{
public:

	Locations locations;

	int currentRoom = 0;

	Player();

	void changeCurrentRoom(int ChangedRoom);

	void Choice();

};

