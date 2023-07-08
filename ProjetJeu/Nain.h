#pragma once
#include "Fantassin.h"
#define PVN 180
#define PdAN 30
#define VitN 2
#define porteeN 1

class Nain : public Fantassin
{
public :
	Nain(Carte* monde);
	virtual void attaquer();
};

