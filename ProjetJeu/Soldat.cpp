#include "Soldat.h"

Soldat::Soldat(string type, Carte* monde) :Fantassin(type, monde)
{
	PV = PVS;
	PdA = PdAS;
}

void Soldat::attaquer()
{
	vector<Fantassin*> ennemis = sonMonde->getVoisins(this);
	if (!ennemis.empty())
	{
		int ennemis_choisi = myRand(0, ennemis.size() - 1);
		ennemis[ennemis_choisi]->setPV(ennemis[ennemis_choisi]->getPV() - getPdA());
	}
}