#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <random>
using namespace std;
#include <iostream>

class Ability {
    public:
    int dmg; // Dégât de la compétence.
    int conso_Mana; // Consommation de mana de la compétence.
    string name; // Nom de la compétence.

        Ability(); // Constructeur de compétence par défaut.
        Ability(int, int, string); // Constructeur de compétence.
        void display(); // Affiche la compétence.
};

#endif
