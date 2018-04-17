#include "Inventory.h"

Inventory::Inventory() {
	nbPotL = 0;
	nbPotM = 0;
}
Inventory::Inventory(int nbr_pot, int nbr_mana) {
	nbPotL = nbr_pot; //nb de potion de vie dans l'inventaire / VALEUR A METTRE DANS CONFIG
	nbPotM = nbr_mana; //nb de potion de mana dans l'inventaire / VALEUR A METTRE DANS CONFIG
}

void Inventory::AddObject(string pot) {
	if (pot == "h"){ //si objet "name" est une potion de vie
		nbPotL += 1 ; //ajout de 1 potion dans l'inventaire
	}

	if (pot == "m") { //si objet "name" est une potion de mana
		nbPotM += 1; //ajout de 1 potion dans l'inventaire
	}
}
