#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <string>
#include "Config.h"
using namespace std;

class Object {
	public:
	string lpName;	//potion de vie
	string mpName; //potion de mana
	int lPotion;
	int mPotion;

		Object();
		Object(Config &conf);
};

#endif
