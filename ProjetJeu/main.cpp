#include <iostream>
#include <ctime>
#include "tools.h"
#include "Carte.h"
#include <vector>
#include "position.h"
#include "Archer.h"
#include "Elfe.h"
#include "Nain.h"
#include "Soldat.h"
#include "Chevalier.h"
#include "Prince.h"
#include "simple_cpp_sockets.h"


using namespace std;
#define Cartel 20
#define CarteL 12


int main()
{
	srand(time(NULL));

	Carte monde(Cartel, CarteL); // Declaration Carte = Damier

	vector<Fantassin*> persos; // Declaration du vecteur qui contiendra tous les persos

	for (int i = 0; i < 5; i++) // Création des perso sur le tas et ajout au vecteur de persos
	{
		Fantassin* persosI = new Fantassin("Fantassin", &monde);
		persos.push_back(persosI);
	}
	for (int i = 0; i < 5; i++) // Création des perso sur le tas et ajout au vecteur de persos
	{
		Archer* persosI = new Archer("Archer", &monde);
		persos.push_back(persosI);
	}
	for (int i = 0; i < 2; i++) // Création des perso sur le tas et ajout au vecteur de persos
	{
		Nain* persosI = new Nain(&monde);
		persos.push_back(persosI);
	}
	for (int i = 0; i < 2; i++) // Création des perso sur le tas et ajout au vecteur de persos
	{
		Elfe* persosI = new Elfe(&monde);
		persos.push_back(persosI);
	}
	for (int i = 0; i < 2; i++) // Création des perso sur le tas et ajout au vecteur de persos
	{
		Soldat* persosI = new Soldat("Soldat", & monde);
		persos.push_back(persosI);
	}
	for (int i = 0; i < 2; i++) // Création des perso sur le tas et ajout au vecteur de persos
	{
		Chevalier* persosI = new Chevalier("Chevalier", & monde);
		persos.push_back(persosI);
	}
	for (int i = 0; i < 6; i++) // Création des perso sur le tas et ajout au vecteur de persos
	{
		Prince* persosI = new Prince("Prince", & monde);
		persos.push_back(persosI);
	}


	for (int i = 0; i < persos.size();) // Pour tous les persos du vecteur persos
		if (monde.setPerso(persos[i])) i++; // si l'ajout du perso à la carte a réussi, alors i+1
	
	int tour = 0;

	while (1)//résolution des déplacements et attaques pour chaque joueurs encore vivants
	{

		for (int j = 0; j < persos.size(); j++)
		{
			persos[j]->deplacer();
			persos[j]->attaquer();

			Fantassin* tmpperso = persos[j];
			for (int i = 0; i < persos.size()-1; i++)
			{
				if (persos[i]->getPV() <= 0)
				{
					persos.erase(persos.begin() + i);
					i--;
				}
			}
			if (persos[persos.size()-1]->getPV() <= 0)
			{
				persos.erase(persos.begin() + persos.size()-1);
			}

			monde.takeDeadPersos();
		}

		int count = monde.PersosCount();
		if (tour % 3 == 0)
		{
			monde.affichageCarte();
			cout << "Il reste " << count << " persos\n";
		}
		//Conditions de fins de partie :
		
		if (count == 1)
		{
			monde.affichageCarte();
			cout << "Partie terminee en " << tour << " tours. Le gagnant est :\n";
			persos[0]->afficher();
			break;
		}
		if (tour == 100)
		{
			cout << "La partie s'est terminee sans gagnant !";
			break;
		}
		tour++;
	}

}