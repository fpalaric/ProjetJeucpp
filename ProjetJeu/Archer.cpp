#include "Archer.h"

Archer::Archer(string type, Carte* monde):Fantassin(type,monde)
{
	PV = PVA;
	PdA = PdAA;
	vitesse = vitA;
	portee = porteeA;
}

void Archer::attaquer()
{
	vector<Fantassin*> ennemis = sonMonde->getVoisins(this);

	if (!ennemis.empty())
	{
		int coupsMax = 2;
		for (int coups = 0; coups < coupsMax; coups++)
		{
			int ennemis_choisi = myRand(0, ennemis.size() - 1);
			ennemis[ennemis_choisi]->setPV(ennemis[ennemis_choisi]->getPV() - getPdA());
		}
		
	}
}