#include "Fight.h"

Fight::Fight() { // Constructeur de la classe "Fight" par défaut.

}

Fight::Fight(Character *hhero, Character *mmonster, Config cconf) { // Constructeur de combat avec le héros et un ennemi.
    hero = hhero; // Récupère les carcatéristiques du héros (PV, mana, compétences, etc...).
    monster = mmonster; // Récupère les carcatéristiques du monstre (PV, mana, compétence, etc...).
    conf = cconf;
}

void Fight::dammage(int dmg, Character *p) { // Calcul des dégâts encaissés par les personnages.
    p->life = p->life - dmg; // "life" (int) : nombre de PV restant au personnage qui reçoit les dégâts.
    cout << p->name << " a reçu " << dmg << " points de dégat." << endl << endl; // Affiche le nombre de PV perdu par le personnage.
    if(p->life <= 0) { // Si le personnage n'a plus de pv, on lance la fonction "end()".
        cout << p->name << " a succombé." << endl << endl;
    }
    if(p->life < 0) {
        p->life = 0;
    }
}

void Fight::manaLoss(int m, Character *p) { // Calcul des PM consommés par la compétence jouée.
    p->mana = p->mana - m; // "mana" (int) : nombre de PM restants au personnage qui lance la compétence.
    if(p->mana < 0) {
        p->mana = 0;
    }
}

void Fight::turn(Character *p1, Character *p2) { // Le joueur p1 joue son tour / Le joueur p2 prend les dégâts.
    bool tmp = false;
    system("clear");
    cout << "         ----------------------------------------         " << endl;
    cout << "Tour de " << p1->name << " : " << endl << endl;

    // SI p1 EST LE HÉROS :
    if(p1->isHero == true) { // Si c'est le tour du héros (bool isHero -> permet de savoir si le personnage est le héros ou un monstre).
        int choice; // Variable entière stockant le choix de la compétence à utiliser.
        cout << "Entrez le numéro de la compétence à jouer : " << endl;
        for(int i = 0; i < p1->nbComp; i++) { // Parcours et affiche les compétences du héros.
            cout << i << ") ";
            p1->comp[i].display();
        }
        cout << p1->nbComp << ") Inventaire" << endl; // Permet de sélectionner l'inventaire.
        cin >> choice; // L'utilisateur entre la compétence choisie.

        ////// Structures préventives //////
        while(cin.fail() || choice < 0 || choice > p1->nbComp) { // Vérifie la conformité de la saisie utilisateur.
            cout << endl;
            cout << "~ La saisie est incorrecte ~" << endl << endl;
            cout << "Entrez le numéro de la compétence à jouer : " << endl;
            for(int i = 0; i < p1->nbComp; i++) {
                cout << i << ") ";
                p1->comp[i].display();
            }
            cout << p1->nbComp << ") Inventaire" << endl; // Permet de sélectionner l'inventaire.
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice; // L'utilisateur entre la compétence choisie.
        }
        cout << endl;

        // Si la compétence demandée consomme un mana supérieur au mana disponible.
        while(p1->mana < p1->comp[choice].conso_Mana) {
            if(tmp == true) { // On passe au tour du monstre si le joueur demande 2 fois de suite une compétence qui consomme trop de PM.
                cout << "Vous n'avez pas assez de mana pour utiliser cette compétence." << endl << endl;
                return; // Termine le tour.
            }
            cout << "Vous n'avez pas assez de mana pour utiliser cette compétence." << endl << "Veuillez en choisir une autre." << endl << endl;
            cout << "Entrez le numéro de la compétence à jouer : " << endl;
            for(int i = 0; i < p1->nbComp; i++) { // Parcours les compétences du héros.
                cout << i << ") ";
                p1->comp[i].display();
            }
            cout << p1->nbComp << ") Inventaire" << endl; // Permet de sélectionner l'inventaire.
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice; // L'utilisateur entre la compétence choisie.
            tmp = true; // Le joueur a demandé une première fois une compétence qui consomme trop de PM.
        }

        // UTILISATION DE L'INVENTAIRE :
        if(choice == p1->nbComp) { // Si le joueur choisi d'ouvrir l'inventaire.
            if(p1->UseObject(conf.pot_life, conf.pot_mana)) {
                return;
            }
            else {
                turn(p1, p2);
            }
        }

        if(choice != p1->nbComp) { // Si le joueur a choisi une compétence.
            Fight::dammage(p1->comp[choice].dmg, p2); // Calcul des dommages de la compétence choisie.
            Fight::manaLoss(p1->comp[choice].conso_Mana, p1); // Perte de mana du personnage jouant liée à la compétence choisie.
            return; // Fin du tour.
        }
    }

    // SI p1 EST LE MONSTRE :
    else if(p1->isHero == false) { // Si c'est le tour du monstre (bool isHero . permet de savoir si le personnage est le héros ou un monstre).

        // Génère un nombre alétoire entre 1 et le nombre de compétences du monstre.
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, p1->nbComp - 1); // "nbComp - 1" pour ne pas sortir du tableau.

        // Vérifie si la compétence est jouable (mana suffisant).
        int c = 0; // Compteur permettant de terminer le tour si le monstre ne trouve pas de compétence consommant peu de PM.
        while(p1->mana < p1->comp[dis(gen)].conso_Mana) {
            if(c == 10) { // Si le monstre ne trouve pas de compétence assez faible en PM.
                cout << "Le monstre n'a plus assez de PM pour attaquer !" << endl;
                return;
            }
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, p1->nbComp - 1);
            c++; // Incrémentation du compteur.
        }


        Fight::dammage(p1->comp[dis(gen)].dmg, p2); // Calcul des dommages de la compétence choisie aléatoirement par le monstre.
        Fight::manaLoss(p1->comp[dis(gen)].conso_Mana, p1); // Perte de mana du personnage jouant liée à la compétence choisie.
        return; // Fin du tour.
    }
}

bool Fight::end(Character *p) { // Détermine si c'est la fin du combat.
    if(p->isHero) { // Si le héros meurt, alors Game Over.
        cout << endl << "GAME OVER..." << endl << endl;
        return true;
    }
    else if(!p->isHero) { // Si le monstre meurt alors le combat est gagné.
        cout << endl << "BRAVO !" << endl << endl;
        return true;
    }
    return false;
}

void Fight::on() { // Fonction globale qui va lancer l'intégralité d'un combat.
    system("clear");
    cout << endl << "Le combat commence !" << endl << endl;
    HUD();
    while(true) { // Boucle infinie.
        if(hero->life <= 0) {end(hero); return;} // Si fin de combat, sort de la fonction.
        cout << endl;
        system( "read -n 1 -s -p \"\"" );
        turn(hero, monster); // Tour du joueur.
        HUD();
        cout << endl;
        system( "read -n 1 -s -p \"\"" );

        if(monster->life <= 0) {end(monster); return;}
        turn(monster, hero); // Tour du monstre.
        HUD();

    }
}

void Fight::HUD() { // Affiche les PV et PM du héros.
    cout << "- " << hero->name << " : " << hero->life << " (vie) / "<< hero->mana << " (mana)" << endl;
    cout << "- " << monster->name << " : " << monster->life << " (vie) / "<< monster->mana << " (mana)" << endl;
}
