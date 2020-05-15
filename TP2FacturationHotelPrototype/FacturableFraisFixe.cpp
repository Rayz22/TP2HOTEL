#include "FacturableFraisFixe.h"
double FacturableFraisFixe::CalculerTotal() {

	if (this->getDescription() == "Spa") {

		double totalSpa = prixSpa;
		totalSpa += totalSpa * (taxeBase + taxeAdditionnelle);
		std::cout << "Spa tx incl.: " << totalSpa << std::endl;
		return totalSpa;
	}

	else {

		double totalGym = prixGym;
		totalGym += totalGym * (taxeBase + taxeAdditionnelle);
		std::cout << "Gym tx incl.: " << totalGym << std::endl;
		return totalGym;
	}

}