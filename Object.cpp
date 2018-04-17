#include "Object.h"

Object::Object() {
	lPotion = 0;
	mPotion = 0;
	lpName = "";
	mpName = "";
}

Object::Object(Config &conf) {
	lPotion = conf.pot_life; //point de vie rendu / VALEUR A METTRE DANS CONFIG
	mPotion = conf.pot_mana; //point de mana rendu / VALEUR A METTRE DANS CONFIG
	lpName = "Potion de vie";
	mpName = "Potion de mana";

}
