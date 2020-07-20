#ifndef STORY_H
#define STORY_H

#include "Player.h"
#include "BeginnersArena.h"
#include <iostream>

class Story {
private:
	BeginnersArena beginnersArena;
public:
	void mainStory(Player player);
	void displayText(std::string text);
	std::string getUserInput(std::string input);
};

#endif


