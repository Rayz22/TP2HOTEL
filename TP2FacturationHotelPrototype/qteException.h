#pragma once
#include <string>
class QteException {
private:
	std::string message;
public:
	QteException(std::string note) {
		this->message = "Le nombre de " +
			note + " doit etre supp�rieur a 0 !\n";
	}
	std::string getMessage() {
		return this->message;
	}
};
