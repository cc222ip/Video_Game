#ifndef CHARACTER_H
#define CHARACTER_H

#include "Ability.h"
#include "Inventory.h"

class Character {
    public:
    int life; // PV du personnage.
    int lifeMax; // PV max
    int mana; // PM du personnage.
    int manaMax; // PM max
    Ability *comp; // Tableau des compétences du personnage.
    int nbComp; // Nombre de compétence du personnage.
    string name; // Nom du personnage.
    bool isHero; // "True" si le personnage est une héros / "False" si c'est un monstre.
    Inventory inv;

        Character(); // Constructeur de la classe "Character" par défaut.
        Character(int, int, Ability *, int, string, bool, Inventory); // Constructeur de la classe "Character".
        ~Character(); // Destructeur de la classe "Character".
        void display();
        bool UseObject(int, int);
};

#endif
