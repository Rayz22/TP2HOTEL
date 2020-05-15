#pragma once
#include <iostream>
#include <string>

class ElementFacturable
{
private:
	std::string description;

public :
	ElementFacturable(std::string Description) { this->description = Description;}

	std::string getDescription()
	{
		return this->description;
	}

	//destructeur
	virtual ~ElementFacturable() {
		std::cout << "Destruction d'un element de la facture." << std::endl;
	}

	virtual double CalculerTotal() = 0;

};




