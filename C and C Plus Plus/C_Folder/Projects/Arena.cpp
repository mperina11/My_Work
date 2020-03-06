#include "pch.h"
#include "Arena.h"

bool Arena::isDone() {
	return done;
}

void Arena::setDone(bool done) {
	this->done = done;
}

std::string Arena::getUserInput(std::string input) {
	std::cin >> input;
	return input;
}
void Arena::displayMenu(std::string menu) {
	std::cout << menu;
}