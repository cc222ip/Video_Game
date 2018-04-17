#ifndef FIGHT_H
#define FIGHT_H

#include "Character.h"
#include "Config.h"

class Fight {
    public:
    Character *hero; // Personnage contrôlé par le joueur.
    Character *monster; // Ennemi unique recontré par le joueur.
    Config conf;

        Fight(); // Constructeur de la classe "Fight" par défaut.
        Fight(Character *, Character *, Config); // Constructeur d'un combat de base avec le héros et un ennemi.
        void turn(Character*, Character*); // Tour de chaque personnage.
        void static dammage(int, Character*); // Calcul des dégâts encaissés par les personnages.
        void static manaLoss(int, Character*); // Calcul de la mana consommé par la compétence jouée.
        bool static end(Character*); // Fin du combat.
        void on(); // Fonction globale qui va lancer l'intégralité d'un combat.
        void HUD(); // Affiche les PV et PM du héros.
};

#endif
