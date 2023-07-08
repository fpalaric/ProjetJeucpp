#include "Carte.h"

//string const nomFichier("C:/Users/Franck/Documents/Formation/C++/Projet/results.json");
//ofstream monFlux(nomFichier.c_str());




Carte::Carte(int l, int L)
{
	largeur = L;
	longueur = l;
	for (int j = 0; j < largeur; j++)
	{
		vector<Fantassin*> tmp;
		for (int i = 0; i < longueur; i++)
		{
			tmp.push_back(nullptr);
		}
		damier.push_back(tmp);
	}
	
	
}

Carte::~Carte()
{
}

bool Carte::setPerso(Fantassin* p)
{	
	int x = myRand(0, longueur - 1);
	int y = myRand(0, largeur - 1);
	if (damier[y][x] == nullptr)
	{
		damier[y][x] = p;
		return true;
	}
	else
		return false;
}

position Carte::getPosition(Fantassin* p)
{
	for (int j = 0; j < largeur; j++)
	{
		for (int i = 0; i < longueur; i++)
		{
			if (damier[j][i] == p)
				return position(i, j);
		}
	}
}

vector<Fantassin*> Carte::getVoisins(Fantassin* p)
{
	vector<Fantassin*> listeVoisins;
	
	int l_min = getPosition(p).getX() - p->getPortee();
	int L_min = getPosition(p).getY() - p->getPortee();
	l_min = l_min >= 0 ? l_min : 0;
	L_min = L_min >= 0 ? L_min : 0;
	int l_max = getPosition(p).getX() + p->getPortee();
	int L_max = getPosition(p).getY() + p->getPortee();
	l_max = l_max <= (longueur - 1) ? l_max : (longueur - 1);
	L_max = L_max <= (largeur - 1) ? L_max : (largeur - 1);

	for(int L = L_min; L <= L_max; L++)
	{
		for (int l = l_min; l <= l_max; l++)
		{
			if (damier[L][l] != nullptr && damier[L][l] != p)
				listeVoisins.push_back(getPersonnage(position(l, L)));
		}
	}
	return listeVoisins;
}

Fantassin* Carte::getPersonnage(position pos)
{
	return damier[pos.getY()][pos.getX()];
}

int Carte::PersosCount()
{
	int count = 0;
	for (int j = 0; j < largeur; j++)
	{
		for (int i = 0; i < longueur; i++)
		{
			if (damier[j][i] != nullptr)
			{
				count++;
			}
		}
	}
	return count;
}

bool Carte::deplacerPerso(Fantassin* p)
{
	int l_min = getPosition(p).getX() - p->getVitesse();
	int L_min = getPosition(p).getY() - p->getVitesse();
	l_min = l_min >= 0 ? l_min : 0;
	L_min = L_min >= 0 ? L_min : 0;
	int l_max = getPosition(p).getX() + p->getVitesse();
	int L_max = getPosition(p).getY() + p->getVitesse();
	l_max = l_max <= (longueur - 1) ? l_max : (longueur - 1);
	L_max = L_max <= (largeur - 1) ? L_max : (largeur - 1);

	int x = myRand(l_min, l_max);
	int y = myRand(L_min, L_max);
	
	if (damier[y][x] == nullptr)
	{
		damier[getPosition(p).getY()][getPosition(p).getX()] = nullptr;
		damier[y][x] = p;
		return true;
	}
	else
		return false;
}

void Carte::takeDeadPersos()
{
	for (int x = 0; x < longueur ; x++)
	{
		for (int y = 0; y < largeur ; y++)
		{
			if (damier[y][x] != nullptr)
			{
				if (damier[y][x]->getPV() <= 0) damier[y][x] = nullptr;
			}
		}
	}
}

void Carte::affichageCarte()
{
	for (int j = 0; j < largeur; j++)
	{
		for (int i = 0; i < longueur; i++)
		{
			if (damier[j][i] != nullptr)
			{
				if (damier[j][i]->getType() == "Fantassin") cout << "F";
				else if (damier[j][i]->getType() == "Archer") cout << "A";
				else if (damier[j][i]->getType() == "Elfe") cout << "E";
				else if (damier[j][i]->getType() == "Nain") cout << "N";
				else if (damier[j][i]->getType() == "Chevalier") cout << "C";
				else if (damier[j][i]->getType() == "Soldat") cout << "S";
				else
					cout << "P";
			}
			else
				cout << ".";
		}
		cout << endl;
	}
}