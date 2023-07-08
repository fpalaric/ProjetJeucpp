#include "Fantassin.h"


Fantassin::Fantassin(string Type, Carte* monde)
{
	PV = PVF;
	PdA = PdAF;
	type = Type;
	portee = porteeF;
	vitesse = vitesseF;
	sonMonde = monde;
}

std::string Fantassin::toString()
{
	std::string s = getType() + " qui a " + std::to_string(getPV()) + "PV";
	return s;
}

void Fantassin::afficher()
{
	cout << toString();
}

void Fantassin::deplacer()
{
	while(!sonMonde->deplacerPerso(this)){};
}

void Fantassin::attaquer()
{
	vector<Fantassin*> ennemis = sonMonde->getVoisins(this);
	for (int j = 0; j < ennemis.size(); j++)
	{
		if (ennemis[j]->getType() == "Fantassin")
		{
			ennemis.erase(ennemis.begin() + j);
			j--;
		}
	}
	if (!ennemis.empty())
	{
	int ennemis_choisi = myRand(0, ennemis.size()-1);
	ennemis[ennemis_choisi]->setPV(ennemis[ennemis_choisi]->getPV() - getPdA());
	}
}

