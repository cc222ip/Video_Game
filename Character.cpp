#include "Character.h"

Character::Character() { // Constructeur de la classe "Character" par défaut.
    life = 0;
    lifeMax = 0;
    manaMax = 0;
    mana = 0;
    nbComp = 0;
    comp = new Ability[nbComp]; // Allocation d'un tableau à une dimension.
    name = "";
    isHero = true;
}

Character::Character(int llife, int mmana, Ability *ccomp, int nnbComp, string nname, bool iisHero, Inventory iinv) { // Constructeur de la classe "Character".
    life = llife; // Initialise les PV avec la valeur fournie en argument.
    mana = mmana; // Initialise les PM avec la valeur fournie en argument.
    lifeMax = life;
    manaMax = mana;
    nbComp = nnbComp; // Initialise le nombre de compétences avec la valeur fournie en argument.
    comp = new Ability[nbComp]; // Allocation d'un tableau à une dimension.
    for(int i = 0; i < nbComp; i++) {
        comp[i] = ccomp[i]; // Rempli le tableau de compétence.
    }
    name = nname; // Initialise le nom du personnage avec la chaîne fournie en argument.
    isHero = iisHero;
    inv = iinv;
}

Character::~Character() { // Destructeur de la classe "Character".
    delete[] comp;
}

void Character::display() {
    cout << "- Nom : " << name << endl;
    cout << "- PV : " << life << endl;
    cout << "- PM : " << mana << endl;
    cout << "- Compétences : " << endl;
    for(int i = 0; i < nbComp; i++) {
        cout << i+1 << ") ";
        comp[i].display();
    }
    if(isHero) {
        cout << name << " est un héros." << endl;
    }
    else if(!isHero) {
        cout << name << " est un monstre." << endl;
    }
}

bool Character::UseObject(int lPotion , int mPotion){
	int choice;
	cout << "Veuillez choisir un objet à utiliser (1 : Potion de vie / 2 : Potion de mana / 3 : Sortir) : " << endl ;
	cin >> choice;

    ////// Structures préventives //////
    while(cin.fail() || choice <= 0 || choice > 3) { // Vérifie la conformité de la saisie utilisateur.
        cout << endl;
        cout << "~ La saisie est incorrecte ~" << endl << endl;
        cout << "Veuillez choisir un objet à utiliser (1 : Potion de vie / 2 : Potion de mana / 3 : Sortir) : " << endl ;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> choice; // L'utilisateur entre la compétence choisie.
    }
    cout << endl;

	if (choice == 1) {
		if(inv.nbPotL > 0){	//si il reste des potions
            if(life == lifeMax) {
                cout << "Vos PV sont à leur maximum." << endl;
                return false;
            }
            else if(life + lPotion > lifeMax) {
                life = lifeMax;
    			cout << "PV : " << life << endl; //point de vie restant
    			cout << "PM : " << mana << endl; //point de mana restant
    			inv.nbPotL -= 1; //retrait de une potion
    			cout << "Potion de vie restantes : " << inv.nbPotL << endl; //nb de potion qu'il reste
            }
            else {
                life += lPotion; //vie rendu
    			cout << "PV : " << life << endl; //point de vie restant
    			cout << "PM : " << mana << endl; //point de mana restant
    			inv.nbPotL -= 1; //retrait de une potion
    			cout << "Potion de vie restantes : " << inv.nbPotL << endl; //nb de potion qu'il reste
            }
		}

		else {
			cout << "Vous n'avez plus de potion de vie." << endl ;
            return false;
		}
	}

	if (choice == 2){
        if(inv.nbPotM > 0){	//si il reste des potions
            if(mana == manaMax) {
                cout << "Vos PM sont à leur maximum." << endl;
                return false;
            }
            else if(mana + mPotion > manaMax) {
                mana = manaMax;
    			cout << "PV : " << life << endl; //point de vie restant
    			cout << "PM : " << mana << endl; //point de mana restant
    			inv.nbPotM -= 1; //retrait de une potion
    			cout << "Potion de mana restantes : " << inv.nbPotM << endl; //nb de potion qu'il reste
            }
            else {
                mana += mPotion; //vie rendu
    			cout << "PV : " << life << endl; //point de vie restant
    			cout << "PM : " << mana << endl; //point de mana restant
    			inv.nbPotM -= 1; //retrait de une potion
    			cout << "Potion de mana restantes : " << inv.nbPotM << endl; //nb de potion qu'il reste
            }
		}

		else {
			cout << "Vous n'avez plus de potion de mana." << endl ;
            return false;
		}
	}

	if (choice == 3) {
		return false; // On sort de l'Inventaire
	}
    return true;
}
