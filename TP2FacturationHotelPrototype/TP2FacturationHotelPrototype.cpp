// TP2FacturationHotelPrototype.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <map>
#include <string>
#include "ElementFacturable.h"
#include "FacturableFraisFixe.h"
#include "FacturableParUnite.h"
#include "qteException.h"
#include "alreadyExistException.h"

static std::map<int, ElementFacturable*> facture;
static void AjouterNuitees();
static void AjouterRepas();
static void AjouterSpa();
static void AjouterGym();
static void AfficherFacture();
int main()
{
	// Clé (key) est un int, Valeur (value) est un std::string.


	int choix = 0;
	do {
		std::cout << "Faites votre choix parmis ce menu : " << std::endl;
		std::cout << "1 - Ajouter des Nuitees" << std::endl;
		std::cout << "2 - Ajouter des Repas" << std::endl;
		std::cout << "3 - Ajouter l'acces au SPA" << std::endl;
		std::cout << "4 - Ajouter l'acces au Gym" << std::endl;
		std::cout << "5 - Afficher la Facture et Quitter" << std::endl;
		std::cin >> choix;

		switch (choix)
		{

		case 1: {
			AjouterNuitees();
		}
			  break;
		case 2: {
			AjouterRepas();
		}
			  break;
		case 3: {
			AjouterSpa();
		}
			  break;
		case 4: {
			AjouterGym();
		}
			  break;
		case 5: {
			AfficherFacture();
		}
			  break;
		};
	} while (choix != 5);

	for (std::map<int, ElementFacturable*>::iterator it = facture.begin();
		it != facture.end(); it++) {
		delete it->second;
		it->second = NULL;
	}
}

    void AjouterNuitees() {
	   int nbrNuitee = 0;
	   try {
		   std::cout << "Combien de nuitees souhaitez-vous ajouter?" << std::endl;
		   std::cin >> nbrNuitee;
		   if (nbrNuitee <= 0) throw QteException("Nuitees");
		   if (facture.find(1) != facture.end()) throw alreadyExistException("Nuitees");
		   FacturableParUnite* nuitee = new FacturableParUnite("Nuitee", nbrNuitee);
		   std::pair<int, FacturableParUnite*> element(1, nuitee);
		   facture.insert(element);
		   std::cout << nbrNuitee << " nuitees ont ete ajoute a la facture avec succes!";
	   }
	   catch (alreadyExistException al) {
		   std::cout << al.getMessage();
		   std::cout << std::endl;
		   FacturableParUnite* nuitee = new FacturableParUnite("Nuitee", nbrNuitee);
		   facture[1] = nuitee;
	   }
	   catch (QteException nbr) {
		   std::cout << nbr.getMessage();
		   std::cout << std::endl;
	   }
   }

	void AjouterRepas() {
		int nbrRepas = 0;
		try {
			std::cout << "Combien de repas souhaitez-vous ajouter?" << std::endl;
			std::cin >> nbrRepas;
			if (nbrRepas <= 0) throw QteException("Repas");
			if (facture.find(2) != facture.end()) throw alreadyExistException("Repas");
			FacturableParUnite* repas = new FacturableParUnite("Repas", nbrRepas);
			std::pair<int, FacturableParUnite*> element(2, repas);
			facture.insert(element);
			std::cout << nbrRepas << " repas ont ete ajoute a la facture avec succes!";
		}
		catch (alreadyExistException al) {
			std::cout << al.getMessage();
			std::cout << std::endl;
			FacturableParUnite* repas = new FacturableParUnite("Repas", nbrRepas);
			facture[2] = repas;
		}
		catch (QteException nbr) {
			std::cout << nbr.getMessage();
			std::cout << std::endl;
		}
	}
	void AjouterSpa() {
		FacturableFraisFixe* spa = new FacturableFraisFixe("Spa", true);
		std::pair<int, FacturableFraisFixe*> element(3, spa);
		facture.insert(element);
		std::cout << "L'acces au Spa a ete ajoute a la facture avec succes!";
	}
	void AjouterGym() {
		FacturableFraisFixe* gym = new FacturableFraisFixe("Gym", true);
		std::pair<int, FacturableFraisFixe*> element(4, gym);
		facture.insert(element);
		std::cout << "L'acces au Gym a ete ajoute a la facture avec succes!";
	}
	void AfficherFacture() {
		double GrandTotal = 0;
		for (std::map<int, ElementFacturable*>::iterator it = facture.begin();
			it != facture.end(); it++) {
			GrandTotal += it->second->CalculerTotal();
		}
		std::cout << "GrandTotal : " << GrandTotal << "$" << std::endl;
	}

