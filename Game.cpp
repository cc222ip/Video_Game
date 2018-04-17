#include <iostream>
#include "Game.h"
#include <unistd.h>
//#include "Map.h"
//#include "Fight.h"

Game::Game(Config &conf){
	nbr_monster = conf.nbr_monster;
	int choice;
		cout << "Bienvenue dans TheGame ."<< endl;
		cout << "Quel héros voulez-vous jouer ? [1-4]"<< endl;
		cout << "1. Guerrier : Combattant solide utilisant des attaques de corps à corps."<< endl;
		cout << "2. Chasseur : Expert des arcs, il préfère attaquer à distance." << endl;
		cout << "3. Voleuse : Experte dans l'art de la furtivité, elle préfère les dagues."<< endl;
		cout << "4. Mage : Expert en magie, il utilise le feu et la foudre contre ses ennemies."<< endl;
		cin >> choice;

		////// Structures préventives //////
        while(cin.fail() || choice <= 0 || choice > 4) { // Vérifie la conformité de la saisie utilisateur.
            cout << endl;
            cout << "~ La saisie est incorrecte ~" << endl << endl;
            cout << "Quel héros voulez-vous jouer ? [1-4]"<< endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice; // L'utilisateur entre la compétence choisie.
        }
        cout << endl;

		Character *c = new Character(conf.heros[choice-1]->life, conf.heros[choice-1]->mana, conf.heros[choice-1]->comp, conf.heros[choice-1]->nbComp, conf.heros[choice-1]->name, conf.heros[choice-1]->isHero, conf.heros[choice-1]->inv);
		Character *monsterfight;
		c->inv.nbPotL = conf.nbr_pot_perso;
		c->inv.nbPotM = conf.nbr_mana_perso;

		Map map( conf , c); //création de la map
		map.repartition();
	string direction = "";
	while (nbr_monster > 0) {
		system("clear");
		map.display(nbr_monster); //affichage map

		// display la map après un déplacement
		cin >> direction;
		string t = map.move(direction, conf);

		while (t == "R" || t == "A"){
			cout << "Où voulez vous allez ? " << endl;
			// display la map après un déplcement
			cin >> direction;
			string t = map.move(direction, conf);
		}
		if (t == "0"){
			int r = rand() % 3;
		 	monsterfight = new Character(conf.monsters[r]->life, conf.monsters[r]->mana, conf.monsters[r]->comp, conf.monsters[r]->nbComp, conf.monsters[r]->name, conf.monsters[r]->isHero, conf.monsters[r]->inv);
			Fight *f = new Fight(c, monsterfight, conf);
			f->on();
			if (c->life > 0) {
				nbr_monster -= 1 ;
			}
		}
		if (t == "h" || t =="m"){
			c->inv.AddObject(t);
		}
	}
	system("clear");
	cout << "Félicitation ! Vous avez fini The Game !" << endl << endl;
	sleep(2);
	cout << "              ~ Crédits ~ " << endl << endl;
	sleep(1);
	cout << "    ~ Chef de projet : Noaman Tata ~" << endl << endl;
	sleep(1);
	cout << "      ~ Équipe de développement : ~" << endl << endl;
	sleep(1);
	cout << "            ~ Noaman Tata ~" << endl << endl;
	sleep(1);
	cout << "          ~ Julien Orlando ~" << endl << endl;
	sleep(1);
	cout << "           ~ Bastien Roure ~" << endl << endl;
	sleep(1);
	cout << "          ~ Chris Chevalier ~" << endl << endl;
	sleep(2);
	cout << "             ~ THE END ~" << endl<< endl<< endl<< endl<< endl;
	system( "read -n 1 -s -p \"Quitter\"" );
	system("clear");
}
