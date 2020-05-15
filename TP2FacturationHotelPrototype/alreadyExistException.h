#pragma once
#include <string>
class alreadyExistException{
private:
	std::string message;
public:
	alreadyExistException(std::string note) {
		this->message = "Des " +
			note + " ont deja ete ajoute a la facture mais nous changerons le nombres par celui que vous venez de nous fournir !\n";
	}
	std::string getMessage() {
		return this->message;
	}
};
