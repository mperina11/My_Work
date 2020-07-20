#include "pch.h"
#include "Menu.h"
#include <iomanip>

Menu::Menu() {
	//default constructor
}

bool Menu::isDone() {
	return done;
}

void Menu::setDone(bool done) {
	this->done = done;
}

void Menu::start() {
	setDone(false);
	displayMenu("Welcome to Battle...\n");
	std::cout << "*********************************************************************\n";
	std::cout << std::setw(56) << "      * *       * * * *     * * * * *   *            *    * *        \n";
	std::cout << std::setw(56) << "     *   *      *       *   *           * *         *    *   *       \n";
	std::cout << std::setw(56) << "    *     *     *  *  *     *           *  *       *    *     *      \n";
	std::cout << std::setw(56) << "   * * * * *    *      *    * * * * *   *   *     *    * * * * *     \n";
	std::cout << std::setw(56) << "  *         *   *       *   *           *    *   *    *         *    \n";
	std::cout << std::setw(56) << " *           *  *        *  *           *     * *    *           *   \n";
	std::cout << std::setw(56) << "*             * *         * * * * * *   *      *    *             *  \n";
	std::cout << "*********************************************************************";

	while (!isDone()) {
		displayMenu("\n1. New Game\n2. Exit\n");
		processUserInput(getUserInput(""));
	}

}

void Menu::displayMenu(std::string menu) {
	std::cout << menu;
}

void Menu::displayOptionError() {
	displayMenu("Please select a valid option\n");
}

std::string Menu::getUserInput(std::string input) {
	std::cin >> input;
	return input;
}

void Menu::processUserInput(std::string choice) {
	if (choice == "1") {
		player = Player(CharacterName());
		story.mainStory(player);
	}
	else if (choice == "2") {
		displayMenu("Thanks for playing!\n");
		setDone(true);
	}
	else {
		displayOptionError();
	}
}

std::string Menu::CharacterName() {
	displayMenu("Enter your character's name: ");
	return getUserInput("");
}
