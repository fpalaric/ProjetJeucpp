#include "Elfe.h"

Elfe::Elfe(Carte* monde):Archer("Elfe", monde)
{
	PV = PVE;
	PdA = PdAE;
	vitesse = vitE;
}