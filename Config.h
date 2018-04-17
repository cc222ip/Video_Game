#ifndef CONFIG_H
#define CONFIG_H
#include "Character.h"

class Config {
public:
	int nbr_monster;			//Nombre de Monstres sur la Carte
	int nbr_obstacle;			//Nombre d'obstacle sur la Carte
	int dim_map;				//Dimension d'un cote de la carte
	int nbr_pot_map;			//Nombre de potion de vie sur la carte
	int nbr_pot_perso;			//Nombre de potion de vie dans l'inventaire du personnage
	int nbr_mana_map;			//Nombre de potion de mana sur la carte
	int nbr_mana_perso;			//Nombre de potion de mana dans l'inventaire du personnage
	int pot_mana;				//Points de mana d'une potion de vie
	int pot_life;				//Points de vie d'une potion de vie
	Character **heros;			//Tableau des Heros
	Character **monsters;		//Tableau des Monstres
	Config();
	void editConfig();
};

#endif
