#ifndef ARENA_H
#define ARENA_H

#include "Player.h"
#include"Enemies.h"
#include "Bosses.h"

#include <iostream>

class Arena {
protected:
	bool done;
public:
	bool isDone();
	void setDone(bool done);
	std::string getUserInput(std::string input);
	void displayMenu(std::string menu);
};

#endif
