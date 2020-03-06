#include "pch.h"
#include "Story.h"

void Story::mainStory(Player player) {
	displayText("\nYou are " + player.getName() + "\n"
		"In order to gain your freedom you will have to beat the champion of the Arena\n"
		"You will start in the beginners Arena and level up to fight the Boss of the Arena\n"
		"You will also earn battle coins with each victory, use them to buy better armor and weapons.\n"
		"Be wise and rest when you need to, it will replenish your health\n\n");
	beginnersArena.enterArena(player);
}

void Story::displayText(std::string text) {
	std::cout << text;
}

std::string Story::getUserInput(std::string input) {
	return input;
}