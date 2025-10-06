#pragma once
#ifndef LOOTTABLE_H
#define LOOTTABLE_H
using namespace std;
#include <string>


struct LootItem
{
	string name;
	int weight;
};

class LootTable
{
private:
	LootItem Items[5];
	int itemCount;
	int totalWeight;

public:
	LootTable();
	void addItem(string name, int weight);
	string rollLoot();
	void displayTable();
};
#endif