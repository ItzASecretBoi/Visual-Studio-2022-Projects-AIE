#pragma once
#include <string>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Entity
{

public:
	// lore stuff
	string name;
	string nametag = name + ":\n";
	string race;
	string description;

	string description_low_health;
	string description_medium_health;
	string description_normal_health;
	int inventory_size;

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

	virtual int attack(Entity& victim);

	void adjustDescription();
};

class Item
{
public:

	string name;
	string description;

	Item();

	virtual int Use();
};


class Bandage : public Item
{
public:

	Bandage();

	int Use() override;

};

class Hostile : public Entity
{

public:

	string encounter_dialogue;

	string death_dialogue;

	int xpDrop = 0;

};




class Room
{

public:
	string name;
	string description;
	string inspect = "I'm not sure how to explain this room...\n\n";

	int roomNorth;
	int	roomSouth;
	int	roomEast;
	int roomWest;

	bool north_is_locked = 0;
	bool south_is_locked = 0;
	bool east_is_locked = 0;
	bool west_is_locked = 0;

	bool Inspected = 0;

	Bandage roomBandage;

	bool room_Has_Bandage = 0;

	bool room_Has_Hostile = 0;

	Room();

	Room(string set_name, string set_description, int set_north, int set_south, int set_east, int set_west);

	Room(string set_name, string set_description, string set_inspect, int set_north, int set_south, int set_east, int set_west);

	Room(string set_name, string set_description, string set_inspect, int set_north, int set_south, int set_east, int set_west, int set_north_locked, int set_south_locked, int set_east_locked, int set_west_locked);


	Hostile enemy;

};

class Locations
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

	bool has_bedroom_key = 0;

	int currentRoom = 0;

	int currentXP = 0;

	string room_description;

	Player();

	void changeCurrentRoom(int ChangedRoom);

	void Choice();

	int levelUp(float level, float currentXP);

	void displayStats(float currentXP);

	int XPForNextLevel(float level);
};
