#include "Ability.h"

Ability::Ability() { // Constructeur de compétence par défaut.
    dmg = 0; // Initialise les dégâts à 0.
    conso_Mana = 0; // Initialise la consommation de PM à 0.
    name = ""; // Initialise le nom de la compétence par défaut.
}

Ability::Ability(int ddmg, int cconso_Mana, string nname) { // Constructeur de compétence.
    dmg = ddmg; // Initialise les dégâts avec la valeur donnée en argument.
    conso_Mana = cconso_Mana; // Initialise la consommation de PM avec la valeur donnée en argument.
    name = nname; // Initialise le nom de la compétence avec le string donné en argument.
}

void Ability::display() {
    cout << this->name << " : " << this->dmg << " (dégât) / " << this->conso_Mana << " (mana)" << endl;
}
