#include "FacturableParUnite.h"
#include <iostream>

double FacturableParUnite::CalculerTotal() {


	if (this->getDescription() == "Nuitee") {

		double totalNuitee = (this->qte * prixNuitee);
		totalNuitee += totalNuitee * (taxeBase + taxeHebergement);
		std::cout << "Nuitees tx incl.: " << totalNuitee << std::endl;
		return totalNuitee;
	}

	else {

		double totalRepas = (this->qte * prixRepas);
		totalRepas += totalRepas * (taxeBase + taxeHebergement);
		std::cout << "Repas tx incl.: " << totalRepas << std::endl;
		return totalRepas;
	}

}