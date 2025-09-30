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
	int inventory_size;

public:

	Entity();

	// stats

	int max_health = 100;
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
public: 

	string name;
	string description;

	Item();

	virtual void Use();
};

class Room
{

public:
	string name;
	string description;
	string inspect = "I'm not sure how to explain this room...\n\n";
	Item items[5];



	int roomNorth;
	int	roomSouth;
	int	roomEast;
	int roomWest;

	bool north_is_locked;
	bool south_is_locked;
	bool east_is_locked;
	bool west_is_locked;


	Room();

	Room(string set_name, string set_description, int set_north, int set_south, int set_east, int set_west);

	Room(string set_name, string set_description, string set_inspect, int set_north, int set_south, int set_east, int set_west);

	Room(string set_name, string set_description, string set_inspect, int set_north, int set_south, int set_east, int set_west, int set_north_locked, int set_south_locked, int set_east_locked, int set_west_locked);

};

class Locations : public Room
{
public:

	Locations();

	Room rooms[10];
};

class Player : public Entity
{
public:

	Item inventory[6];

	Locations locations;

	int currentRoom = 0;

	Player();

	void changeCurrentRoom(int ChangedRoom);

	void Choice();

};

class BandAid : public Item
{
private:
	string name;
	string description;

public:

	void Use(Player player);
};