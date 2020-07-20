#ifndef MENU_H
#define MENU_H

#include "Player.h"
#include "Story.h"
#include <iostream>

class Menu {
private:
	bool done = false;
	Story story;
	Player player;
public:
	Menu();
	bool isDone();
	void setDone(bool done);
	void start();
	void displayMenu(std::string menu);
	void displayOptionError();
	void processUserInput(std::string choice);
	std::string getUserInput(std::string menu);
	std::string CharacterName();
};

#endif

