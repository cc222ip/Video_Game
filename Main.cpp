#include "Config.h"
#include "Game.h"
#include "Character.h"
#include "Inventory.h"
#include "Fight.h"
#include "Map.h"
#include <iostream>
#include <unistd.h>

int main() {
	int choice;
	Config C;
	bool menu = true;
	bool first = true;
	while(menu){
		system("clear");
		if(first){
			first = false;
			cout << "Bienvenue dans The Game !" << endl << endl;
			sleep(2);
		}
		else{
			cout << "The Game" << endl << endl;
		}
		cout << "Menu Principal" << endl;
		sleep(1);
		cout << "1. Jouer" << endl;
		cout << "2. Configurer" << endl;
		cout << "3. Rgles du Jeu" << endl;
		cout << "4. Quitter" << endl;
		cin >> choice;
		////// Structures préventives //////
        while(cin.fail() || choice <= 0 || choice > 4) { // Vérifie la conformité de la saisie utilisateur.
            cout << endl;
            cout << "~ La saisie est incorrecte ~" << endl << endl;
            cout << "Quel est votre choix du menu principal ? [1-4]"<< endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice; // L'utilisateur entre son choix du menu principal choisie.
        }
		system("clear");
        cout << endl;
		switch (choice) {
		case 1: {
			menu = false;
			Game G(C);
			break;
		}
		case 2: {
			C.editConfig();
			sleep(2);
			break;
		}
		case 3: {
			cout << "Règles du jeu :" << endl << endl;
			sleep(1);
			cout << "Afin de reussir à gagner la partie, vous allez devoir tuer tous les monstres présents sur la carte a l'aide des sorts qui vous seront assignés."  << endl;
			cout << "Mais pour vous aidez dans cette quête, vous obtiendrez des potions de vie et de mana directement dans votre inventaire mais aussi sur la carte." << endl;
			cout << "Les monstres seront de différents niveaux, en partant de la simple goule au dragon." << endl;
			cout << "Il vous faudra donc faire attention à la gestion de votre mana et de votre vie afin de ne pas vous retrouver sans defense lors d'un combat plus difficile." << endl;
			cout << "La partie peut aussi s'arrêter si vos points de vie atteignent 0." << endl << endl;
			sleep(10);
			cout << "Bonne chance dans The Game !" << endl;
			sleep(2);
			break;
		}
		case 4:
			menu = false;
			break;
		}
	}
	return 0;
}
