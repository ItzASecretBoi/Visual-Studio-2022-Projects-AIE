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

class Room
{
public:
	string name;
	string description;
	Item items[5];

	Room();

	Room(string set_name, string set_description, Item items[5]);

};


class Player : public Entity
{
	public:

		Room currentRoom;

		Player();

		void changeCurrentRoom(Room nextRoom);

		int choice(int choice);

		
};

