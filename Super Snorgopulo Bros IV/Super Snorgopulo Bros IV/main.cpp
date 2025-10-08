#include <iostream>
#include "function.h"
#include <fstream>

using namespace std;

int playerChoice;

//struct GameCharacter
//{
//	string name = "Godothphramew";
//	int health = 69;
//	int level = 21;
//};
//
//class BankAccount
//{
//	private:
//		int balance = 100;
//		int accountNumber;
//
//	public:
//		int deposit(int deposit)
//		{
//			return balance += deposit;
//		}
//
//		int getBalance()
//		{
//			return balance;
//		}
//
//		int setAccountNumber(int number)
//		{
//			return accountNumber = number;
//		}
//};
//
//
//struct HomeAddress
//{
//	string street;
//	string city;
//	int zip;
//};
//
//struct Player
//{
//	string name;
//	HomeAddress address;
//	int score = 0;
//};

//class student
//{
//private:
//	string name;
//	float gpa;
//	int student_id;
//	
//public:
//
//	student()
//	{
//		name = "unknown";
//		student_id = 0;
//		gpa = 0.0;
//	}
//
//	student(string set_name, int id)
//	{
//		name = set_name;
//		student_id = id;
//		gpa = 0.0;
//	}
//
//	void display()
//	{
//		cout << name << endl << endl;
//		cout << student_id << endl << endl;
//	};


	class Weapon
	{

	private:
		
		string name;
		int durability;
		float damage;

	public:
		
		Weapon()
		{
			name = "MyWeapon";
			durability = 100;
			damage = 1.5;
		}

		Weapon(string weaponName)
		{
			name = weaponName;
			durability = 100;
			damage = 1.5;
		}

		Weapon(string weaponName, int weaponDurability, int weaponDamage)
		{
			name = weaponName;
			durability = weaponDurability;
			damage = weaponDamage;
		}

		void display()
		{
			cout << name << endl << endl;
			cout << durability << endl << endl;
			cout << damage << endl << endl;
		}
	};

	//class Item
	//{
	//protected:
	//	string name;

	//public:
	//	Item()
	//	{
	//		cout << "Item constructer called..." << endl;
	//		name = "apple";
	//	}

	//	Item(string itemName)
	//	{
	//		cout << "Item constructer with name called.." << endl;
	//		name = itemName;
	//	}

	//	void display()
	//	{
	//		cout << name << endl << endl;
	//	}

	//};

	//class Sword : public Item
	//{
	//public:
	//	Sword()
	//	{
	//		cout << "Sword constructer called!" << endl;
	//	}

	//	Sword(string itemname)
	//	{
	//		cout << "Sword with name was called!";
	//	}
	//};

	class Animal
	{
	protected:

		string name;
		int age = 1;

	public:

		virtual void makeSound()
		{
			cout << "A nearby animal makes a noise!" << name << endl << endl;
		}

		void display()
		{
			cout << "Name: " << name << endl << endl;
			cout << "Age: " << age << endl << endl;
		}
	};

	class Cat : public Animal
	{
	public:
		Cat()
		{
			name = "Cat";
			age = 2;
		}

		void makeSound() override
		{
			cout << "A nearby animal makes a noise, it sounds like 'meow!'." << endl << endl;
		}
	};

	class Dog : public Animal
	{
	public:
		Dog()
		{
			name = "Dog";
			age = 5;
		}

		void makeSound() override
		{
			cout << "A nearby animal makes a noise, it sounds like 'bark!'." << endl << endl;
		}
	};

	class Vehicle
	{
		public:
			int speed;
			string color;

		void display()
		{
			cout << "Speed: " << speed << endl << endl;

			cout << "Color:" << color << endl << endl;

		}
	};

	class Car : public Vehicle
	{
		public:
			Car()
			{
				speed = 2;

				color = " Green or something idk";
			}

			void Honk()
			{
				cout << "BEEP!" << endl << endl;
			}

	};

	class GameCharacter
	{
	public: 
		int health = 100;
		string name = "Bob";
	};

	class Warrior : public GameCharacter
	{
	public:
		string weapon = "Sword";

		void display()
		{
			cout << "Name: " << name << endl << endl << "Weapon: " << weapon << endl << endl;
		}
	};

	class Shape
	{
	public:
		virtual void drawShape()
		{
			cout << "i be drawing a shape bruh" << endl << endl;
		}
	};

	class Circle : public Shape 
	{
	public:
		void drawShape() override
		{
			cout << "i be drawing a curicle bruh" << endl << endl;
		}
	};
	
	class Item
	{
		public:
			virtual void use()
			{
				cout << "Item Used..." << endl << endl;
			}
	};

	class Sword : public Item
	{
	public:
		void use() override
		{
			cout << "You Swung A Sword!" << endl << endl;
		}
	};

int main()
{	
	Sword apple;

	Item ainsk;

	ainsk.use();

	apple.use();

}

