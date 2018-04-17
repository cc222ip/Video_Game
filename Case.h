#ifndef CASE_H
#define CASE_H
#include <iostream>
#include <string>
#include <random>
#include <stdlib.h>
using namespace std;

class Case {

	string case_type;			// type de la case (arbre, monstre , potion etc..
	int x;						// Coordonnée x
	int y;						// et y
	friend class Map;
public:

	//	Case();

};
#endif
