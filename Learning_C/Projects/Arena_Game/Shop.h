#ifndef SHOP_H
#define SHOP_H

#include "Player.h"

class Shop {
private:
	bool done;
public:
	void enterShop(Player& player);
	void displayMenu(std::string menu);
};

#endif
