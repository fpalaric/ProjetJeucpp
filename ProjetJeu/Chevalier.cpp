#include "Chevalier.h"

Chevalier::Chevalier(string type, Carte* monde):Soldat(type, monde)
{
	vitesse = VitC;
	portee = porteeC;
}