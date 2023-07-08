#pragma once
#include <vector>
#include "Fantassin.h"
#include "position.h"
#include <fstream>
#include <sstream>
using namespace std;

class Fantassin;

class Carte
{
	int largeur;
	int longueur;
	vector<vector<Fantassin*>> damier;
public :
	Carte(int l, int L);
	~Carte();

	bool setPerso(Fantassin* p);
	position getPosition(Fantassin* p);
	vector<Fantassin*> getVoisins(Fantassin* p);
	Fantassin* getPersonnage(position pos);
	int PersosCount();
	bool deplacerPerso(Fantassin* p);
	void takeDeadPersos();
	void affichageCarte();

};

