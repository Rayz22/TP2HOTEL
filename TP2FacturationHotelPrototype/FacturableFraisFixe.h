#pragma once
#include <iostream>
#include <string>
#include "ElementFacturable.h"

class FacturableFraisFixe : public ElementFacturable{
private:
	bool accesAutorise = false;
	const double prixSpa = 75;
	const double prixGym = 50;
	const double taxeBase = 0.08;
	const double taxeAdditionnelle = 0.07;
public:
	FacturableFraisFixe(std::string Description, bool acces_Autorise)
		:ElementFacturable(Description) {
	
		this->accesAutorise = acces_Autorise;
	
	}
	
	virtual double CalculerTotal();

};
