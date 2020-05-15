#pragma once
#include <iostream>
#include <string>
#include "ElementFacturable.h"

class FacturableParUnite : public ElementFacturable
{
private:
	int qte;
	const double prixNuitee = 100;
	const double prixRepas = 20;
	const double taxeBase = 0.08;
	const double taxeHebergement = 0.05;

public:
	FacturableParUnite(std::string Description, int une_qte) : ElementFacturable(Description) {

		this->qte = une_qte;

	}
	
	virtual double CalculerTotal();
};

