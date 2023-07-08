#pragma once
#include "Fantassin.h"
#define PVS 110
#define PdAS 20

class Soldat : public Fantassin
{
public :	
	Soldat(string type, Carte* monde);
	virtual void attaquer();
};

