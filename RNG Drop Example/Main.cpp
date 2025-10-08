#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	LootTable FruitLord;

	FruitLord.addItem("Apple", 50);
	FruitLord.addItem("Bannana", 50);
	FruitLord.addItem("Durian", 5);

	FruitLord.displayTable();

	cout << endl;
	cout << "=== Roll Simulation ===" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Drop " << (i + 1) << ": " << FruitLord.rollLoot() << endl;
	}

	return 0;
}