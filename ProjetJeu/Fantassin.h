#pragma once
#include <string>
#include "tools.h"
#include "Carte.h"
#include "position.h"
#define PVF 100
#define PdAF 15
#define porteeF 2
#define vitesseF 3
class Carte;

class Fantassin
{
protected :
	int PV;
	int PdA;
	std::string type;
	int portee;
	int vitesse;
	Carte* sonMonde;
public :
	Fantassin(string Type, Carte* monde);
	
	int getPV() { return PV; }
	int getPdA() { return PdA; }
	std::string getType() { return type; }
	int getPortee() { return portee; }
	int getVitesse() { return vitesse; }
	void setPV(int pt) { PV = pt; }
	void setPdA(int ptAt) { PdA = ptAt ; }
	void setPortee(int ptPort) { portee = ptPort; }
	void setVitesse(int vit) { vitesse = vit; }
	
	
	std::string toString();
	void afficher();
	virtual void deplacer();
	virtual void attaquer();
};

