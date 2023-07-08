#include "Prince.h"

Prince::Prince(string type, Carte* monde) :Chevalier(type, monde)
{
	PdA = PdAP;
	PV = PVP;
}

void Prince::attaquer()
{
	vector<Fantassin*> ennemis = sonMonde->getVoisins(this);
	if (!ennemis.empty())
	{
		for(int j = 0; j < ennemis.size(); j++)
		ennemis[j]->setPV(ennemis[j]->getPV() - getPdA());
	}
}