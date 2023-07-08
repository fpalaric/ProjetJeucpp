#pragma once
#include "Soldat.h"
#include "Carte.h"
#define VitC 10
#define porteeC 4

class Chevalier:public Soldat
{
public :
	Chevalier(string type, Carte* monde);
};

