#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>

using namespace std;

class Inventory {
	public :
	int nbPotL; //nb de potion de vie
	int nbPotM; //nb de potion de mana

		Inventory();
		Inventory(int, int);
		void AddObject(string);
};
#endif
