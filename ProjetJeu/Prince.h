#pragma once
#include "Chevalier.h"
#define PdAP 60
#define PVP 150

class Prince:public Chevalier
{
public :
	Prince(string type, Carte* monde);
	virtual void attaquer();
};

