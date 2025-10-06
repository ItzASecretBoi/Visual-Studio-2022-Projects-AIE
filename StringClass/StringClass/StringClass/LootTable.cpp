#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include "StringClass.h"
#include "LootTable.h"

using namespace std;

LootTable::LootTable()
{
	totalWeight = 0;
	itemCount = 0;
	srand(time(0));
}

void LootTable::addItem(string name, int weight)
{
	if(itemCount < 5)
	{
		Items[itemCount].name = name;
		Items[itemCount].weight = weight;
		totalWeight += weight;
		itemCount++;
	}
}

string LootTable::rollLoot()
{
	if(itemCount == 0)
	{
		return "nothing...";
	}

	int roll = rand() & totalWeight;
	int cumulative = 0;

	for(int i = 0; i < itemCount; i++)
	{
		cumulative += Items[i].weight;
		if(roll < cumulative)
		{
			return Items[i].name;
		}
	}

	return Items[0].name;
}

void LootTable::displayTable()
{
	cout << "=== Loot Table ===" << endl;
	for(int i = 0; i < itemCount; i++)
	{
		float chance = (Items[i].weight / (float)totalWeight) * 100;
		cout << Items[i].name << ": " << chance << "%" << endl;
	}
}