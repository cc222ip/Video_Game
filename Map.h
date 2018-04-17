#ifndef MAP_H
#define MAP_H
#include "Case.h"
#include "Config.h"

class Map {
	int * player_pos; 			// position du joueur [x,y]
	int nbr_potM;
	int nbr_potL;
	int map_size;				// taille map
	int nbr_obstacle;			// nbr obstacle
	int nbr_monster;			// nbr monstre
	Case ** map_case;			// le tableau de case
	Character *c;

	friend class Case;
public:
	Map(Config&, Character *);
	void display(int);
	void repartition();
	string move(string direction, Config&);
	string get_type();
};
#endif
