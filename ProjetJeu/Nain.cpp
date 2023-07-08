#include "Nain.h"

Nain::Nain(Carte* monde):Fantassin("Nain",monde)
{
	PV = PVN;
	PdA = PdAN;
	vitesse = VitN;
	portee = porteeN;
}

void Nain::attaquer()
{
	vector<Fantassin*> ennemis = sonMonde->getVoisins(this);
	

	if (!ennemis.empty())
	{
		for (int j = 0; j < ennemis.size(); j++)
		ennemis[j]->setPV(ennemis[j]->getPV() - getPdA());
	}
}
