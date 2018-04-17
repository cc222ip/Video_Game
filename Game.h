#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;
#include "Config.h"
#include "Map.h"
#include "Fight.h"
class Game{

	int nbr_monster; //nb de monstre

	public :
		Game(Config &conf);
};
#endif
