#include "Config.h"

Config::Config(){
	nbr_monster = 9;					//Nombre de Monstres sur la Carte
	nbr_obstacle = 15;					//Nombre d'obstacle sur la Carte
	dim_map = 20;						//Dimension d'un cote de la carte
	nbr_pot_map = 3;					//Nombre de potion de vie sur la carte
	nbr_pot_perso = 2;					//Nombre de potion de vie dans l'inventaire du héros
	nbr_mana_map = 3;					//Nombre de potion de mana sur la carte
	nbr_mana_perso = 2;					//Nombre de potion de mana dans l'inventaire du héros
	pot_mana = 50;						//Points de mana d'une potion de mana
	pot_life = 50;						//Points de vie d'une potion de vie
	heros = new Character*[4];			//Tableau des Heros
	monsters = new Character*[3];		//Tableau des Monstres
	Ability *Abh = new Ability[2];		//Tableau des Compétences pour un héros
	Inventory inv(0, 0);				//Inventaire du héros ou du monstre

	Abh[0] = Ability(50, 0, "Coup d'épée");
	Abh[1] = Ability(400, 25, "Epee divine");
	heros[0] = new Character(800, 100, Abh, 2, "Guerrier", true, inv);

	Abh[0] = Ability(75, 0, "Tir charge");
	Abh[1] = Ability(400, 25, "Tir perforant");
	heros[1] = new Character(500, 100, Abh, 2, "Chasseur", true, inv);

	Abh[0] = Ability(150, 0, "Assassinat");
	Abh[1] = Ability(300, 15, "Coup Furtif");
	heros[2] = new Character(250, 100, Abh, 2, "Voleuse", true, inv);

	Abh[0] = Ability(120, 0, "Brasier");
	Abh[1] = Ability(300, 15, "Foudre");
	heros[3] = new Character(350, 100, Abh, 2, "Mage", true, inv);

	Ability *Abm = new Ability[1];		//Tableau des Compétences pour un monstre
	Abm[0] = Ability(20, 2, "Morsure");
	monsters[0] = new Character(70, 100, Abm, 1, "Goule", false, inv);

	Abm[0] = Ability(40, 4, "Griffe de l'ombre");
	monsters[1] = new Character(200, 100, Abm, 1, "Demon", false, inv);

	Abm[0] = Ability(80, 8, "Souffle de Feu");
	monsters[2] = new Character(500, 100, Abm, 1, "Dragon", false, inv);
}

void Config::editConfig() {
	int choice;
	Character *Charac = NULL;
	bool menu = true;
	bool sousmenu1 = true;
	bool sousmenu2 = true;
	while(menu){
		menu = false;
		sousmenu1 = true;
		sousmenu2 = true;
		cout << "Configuration" << endl;
		cout << "Quel Heros ou Monstres ou Carcteristiques du jeu souhaitez-vous modifier ?" << endl;
		cout << "Pour la configuration des Heros ou des Montres, Sous-menu existant" << endl;
		cout << "1." << heros[0]->name << " : combattant solide utilisant des attaques de corps a corps " << endl;
		cout << "2." << heros[1]->name << " : expert des arcs , il prefere attaque a distance " << endl;
		cout << "3." << heros[2]->name << " : experte dans l'art de la furtivite , elle prefere les dagues " << endl;
		cout << "4." << heros[3]->name << " : expert en magie , il utilise le feu et la foudre contre ses ennemies " << endl;
		cout << "5." << monsters[0]->name << " : une creature monstrueuse " << endl;
		cout << "6." << monsters[1]->name << " : un etre surnaturel et doue de raison " << endl;
		cout << "7." << monsters[2]->name << " : une creature legendaire representee comme une sorte de gigantesque reptile " << endl;
		cout << "8. Nombre de Monstres sur la Carte" << endl;
		cout << "9. Nombre de Monstres sur la Carte" << endl;
		cout << "10. Dimension d'un cote de la carte" << endl;
		cout << "11. Nombre de potion de vie sur la carte" << endl;
		cout << "12. Nombre de potion de vie dans l'inventaire du héros" << endl;
		cout << "13. Nombre de potion de mana sur la carte" << endl;
		cout << "14. Nombre de potion de mana dans l'inventaire du héros" << endl;
		cout << "15. Points de mana d'une potion de mana" << endl;
		cout << "16. Points de vie d'une potion de vie" << endl;
		cout << "0. Retour au menu <=[" << endl;
		cin >> choice;
		////// Structures préventives //////
        while(cin.fail() || choice < 0 || choice > 16) { // Vérifie la conformité de la saisie utilisateur.
            cout << endl;
            cout << "~ La saisie est incorrecte ~" << endl << endl;
            cout << "Quel Heros ou Monstres ou Carcteristiques du jeu souhaitez-vous modifier ? [0-16]"<< endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice; // L'utilisateur entre son choix du menu principal choisie.
        }
        if(choice < 8){
        	system("clear");
        }
        else{
        	sousmenu1 = false;
        }
		switch (choice) {
			case 0: {
				return;
			}
			case 1: {
				Charac = heros[0];
				break;
			}
			case 2: {
				Charac = heros[1];
				break;
			}
			case 3: {
				Charac = heros[2];
				break;
			}
			case 4: {
				Charac = heros[3];
				break;
			}
			case 5: {
				Charac = monsters[0];
				break;
			}
			case 6: {
				Charac = monsters[1];
				break;
			}
			case 7: {
				Charac = monsters[2];
				break;
			}
			case 8: {
				cout << "Nouvelle Valeur = " << endl;
				cin >> nbr_monster;
				break;
			}
			case 9: {
				cout << "Nouvelle Valeur = " << endl;
				cin >> nbr_obstacle;
				break;
			}
			case 10: {
				cout << "Nouvelle Valeur = " << endl;
				cin >> dim_map;
				break;
			}
			case 11: {
				cout << "Nouvelle Valeur = " << endl;
				cin >> nbr_pot_map;
				break;
			}
			case 12: {
				cout << "Nouvelle Valeur = " << endl;
				cin >> nbr_pot_perso;
				break;
			}
			case 13: {
				cout << "Nouvelle Valeur = " << endl;
				cin >> nbr_mana_map;
				break;
			}
			case 14: {
				cout << "Nouvelle Valeur = " << endl;
				cin >> nbr_mana_perso;
				break;
			}
			case 15: {
				cout << "Nouvelle Valeur = " << endl;
				cin >> pot_mana;
				break;
			}
			case 16: {
				cout << "Nouvelle Valeur = " << endl;
				cin >> pot_life;
				break;
			}
		}
		while(sousmenu1){
			sousmenu1 = false;
			sousmenu2 = true;
			Charac->display();
			cout << endl << "Quel caracteristique souhaitez-vous modifier ?" << endl;
			cout << "1. Les Points de Vie" << endl;
			cout << "2. Les Points de Mana" << endl;
			cout << "3. Une Competence (sous-menu)" << endl;
			cout << "4. Le Nom" << endl;	
			cout << "0. Retour <=[" << endl;
			cin >> choice;
			////// Structures préventives //////
		    while(cin.fail() || choice < 0 || choice > 4) { // Vérifie la conformité de la saisie utilisateur.
		        cout << endl;
		        cout << "~ La saisie est incorrecte ~" << endl << endl;
		        cout << "Quel caracteristique souhaitez-vous modifier ? [0-4]"<< endl;
		        cin.clear();
		        cin.ignore(256, '\n');
		        cin >> choice; // L'utilisateur entre son choix du menu principal choisie.
		    }
			switch (choice) {
				case 0: {
					menu = true;
					system("clear");
					break;
				}
				case 1: {
					cout << "Nouvelle Valeur = " << endl;
					cin >> Charac->life;
					break;
				}
				case 2: {
					cout << "Nouvelle Valeur = " << endl;
					cin >> Charac->mana;
					break;
				}
				case 3: {
					while(sousmenu2){
						sousmenu2 = false;
						system("clear");
						Charac->comp[0].display();
						if(Charac->nbComp == 2) {
							Charac->comp[1].display();
							cout << endl << "Quel caracteristique d'une competence souhaitez-vous modifier ?" << endl;
							cout << "1. Nom de "<< Charac->comp[0].name << endl;
							cout << "2. Degat de " << Charac->comp[0].name << endl;
							cout << "3. Consomation de mana de " << Charac->comp[0].name  << endl;
							cout << "4. Nom de "<< Charac->comp[1].name << endl;
							cout << "5. Degat de " << Charac->comp[1].name << endl;
							cout << "6. Consomation de mana de " << Charac->comp[1].name  << endl;
							cout << "0. Retour <=[" << endl;
							cin >> choice;
							////// Structures préventives //////
							while(cin.fail() || choice < 0 || choice > 6) { // Vérifie la conformité de la saisie utilisateur.
								cout << endl;
								cout << "~ La saisie est incorrecte ~" << endl << endl;
								cout << "Quel caracteristique d'une competence souhaitez-vous modifier ? [0-6]"<< endl;
								cin.clear();
								cin.ignore(256, '\n');
								cin >> choice; // L'utilisateur entre son choix du menu principal choisie.
							}
							cout << endl;
							if(choice != 0){
								cout << "Nouvelle Valeur = " << endl;
							}
							switch (choice) {
								case 0: {
									sousmenu1 = true;
									system("clear");
									break;
								}
								case 1: {
									cin >> Charac->comp[0].name;
									break;
								}
								case 2: {
									cin >> Charac->comp[0].dmg;
									break;
								}
								case 3: {
									cin >> Charac->comp[0].conso_Mana;
									break;
								}
								case 4: {
									cin >> Charac->comp[1].name;
									break;
								}
								case 5: {
									cin >> Charac->comp[1].dmg;
									break;
								}
								case 6: {
									cin >> Charac->comp[1].conso_Mana;
									break;
								}
							}
						}
						else {
							cout << endl << "Quel caracteristique de competence souhaitez-vous modifier ?" << endl;
							cout << "1. Nom de "<< Charac->comp[0].name << endl;
							cout << "2. Degat de " << Charac->comp[0].name << endl;
							cout << "3. Consomation de mana de " << Charac->comp[0].name  << endl;
							cout << "0. Retour <=[" << endl;
							cin >> choice;
							////// Structures préventives //////
							while(cin.fail() || choice < 0 || choice > 3) { // Vérifie la conformité de la saisie utilisateur.
								cout << endl;
								cout << "~ La saisie est incorrecte ~" << endl << endl;
								cout << "Quel caracteristique de competence souhaitez-vous modifier ? [0-3]"<< endl;
								cin.clear();
								cin.ignore(256, '\n');
								cin >> choice; // L'utilisateur entre son choix du menu principal choisie.
							}
							cout << endl;
							if(choice != 0){
								cout << "Nouvelle Valeur = " << endl;
							}
							switch (choice) {
								case 0: {
									sousmenu1 = true;
									system("clear");
									break;
								}
								case 1: {
									cin >> Charac->comp[0].name;
									break;
								}
								case 2: {
									cin >> Charac->comp[0].dmg;
									break;
								}
								case 3: {
									cin >> Charac->comp[0].conso_Mana;
									break;
								}
							}
						}
					}
					break;
				}
				case 4: {
					cout << "Nouvelle Valeur = " << endl;
					cin >> Charac->name;
					break;
				}
			}
		}
	}
	cout << endl << "Modification effectue !" << endl;
}
