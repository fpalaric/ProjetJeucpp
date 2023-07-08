#pragma once
#include "Fantassin.h"
#define PVA 80
#define PdAA 20
#define porteeA 8
#define vitA 4

class Archer : public Fantassin
{
public :
	Archer(string type, Carte* monde);
	virtual void attaquer();
};

