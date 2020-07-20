#ifndef BEGINNERS_ARENA_H
#define BEGINNERS_ARENA_H


#include "Arena.h"
#include "Shop.h"
#include "Bosses.h"

class BeginnersArena : public Arena {
private:
	Arena arena;
	Shop shop;
public:
	void enterArena(Player player);
	void fightArena(Player& player);
	void arenaRest(Player& player);
	void bossFight(Player& player);
	void displayMenu(std::string menu);
	std::vector<std::string> x;			//vector to store beaten enemies 
};

#endif
