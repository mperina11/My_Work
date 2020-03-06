#include "pch.h"
#include "Shop.h"

void Shop::enterShop(Player& player) {
	bool done = false;
	while (!done) {
		displayMenu("Welcome to the Arena Shop!\n"
			"What do you want to buy?\n"
			"1. Weapons\n"
			"2. Armor\n"
			"3. Exit\n");
		std::string choice;
		std::cin >> choice;
		if (choice == "1") {
			bool done3 = false;
			while (!done3) {
				std::cout << "\nYou have " << player.getMoney() << " coins.\n"
					<< "Weapons:\n";
				displayMenu("1. Iron Sword [10]\n"
					"2. Spartan Spear [15]\n"
					"3. Bow [15]\n"
					"4. Exit\n");
				std::string choice;
				std::cin >> choice;

				if (choice == "1") {
					if (player.getMoney() >= 10 && player.getWeapon() == 0) {
						displayMenu("You purchased Iron Sword\n");
						player.subtractMoney(10);
						player.boostStrength(3);
						player.addWeapon(1);
					}
					else if (player.getWeapon() == 1) {
						displayMenu("You already have this weapon.\n");
					}
					else if (player.getWeapon() > 1) {
						displayMenu("You have a better weapon.\n");
					}
					else {
						displayMenu("You don't have enough coins to buy this.\n");
					}
				}
				else if (choice == "2") {
					if (player.getMoney() >= 15 && (player.getWeapon() == 1 || player.getWeapon() == 0)) {
						if (player.getWeapon() == 0) {
							player.boostStrength(3);
							player.addWeapon(1);
						}
						displayMenu("You purchased Spartan Spear\n");
						player.subtractMoney(15);
						player.boostStrength(5);
						player.addWeapon(1);

					}
					else if (player.getWeapon() == 2) {
						displayMenu("You already have this weapon.\n");
					}
					else if (player.getWeapon() > 2) {
						displayMenu("You have a better weapon.\n");
					}
					else {
						displayMenu("You don't have enough coins to buy this.\n");
					}
				}
				else if (choice == "3") {
					if (player.getMoney() >= 15 && (player.getWeapon() == 1 || player.getWeapon() == 2 || player.getWeapon() == 0)) {
						if (player.getWeapon() == 0) {
							player.boostStrength(8);
							player.addWeapon(2);
						}
						else if (player.getWeapon() == 1) {
							player.boostStrength(5);
							player.addWeapon(1);
						}
						displayMenu("You purchased Bow\n");
						player.subtractMoney(15);
						player.boostStrength(5);
						player.addWeapon(1);
					}
					else if (player.getWeapon() == 3) {
						displayMenu("You already have this weapon.\n");
					}
					else if (player.getWeapon() > 3) {
						displayMenu("You have a better weapon.\n");
					}
					else {
						displayMenu("You don't have enough coins to buy this.\n");
					}
				}
				else if (choice == "4") {
					done3 = true;
				}
			}
		}
		else if (choice == "2") {
			bool done4 = false;
			while (!done4) {
				std::cout << "\nYou have " << player.getMoney() << " coins.\n"
					<< "Armor:\n";
				displayMenu("1. Leather Armor [10]\n"
					"2. Iron Chestplate [15]\n"
					"3. Full Iron Armor [20]\n"
					"4. Spiked Chestplate [20]\n"
					"5. Exit\n");
				std::string choice;
				std::cin >> choice;

				if (choice == "1") {
					if (player.getMoney() >= 10 && player.getArmor() == 0) {
						displayMenu("You purchased Leather Armor\n");
						player.subtractMoney(10);
						player.boostHealth(6);
						player.addArmor(1);
					}
					else if (player.getArmor() == 1) {
						displayMenu("You already have this armor.\n");
					}
					else if (player.getArmor() > 1) {
						displayMenu("You have better armor.\n");
					}
					else {
						displayMenu("You don't have enough coins to buy this.\n");
					}
				}
				else if (choice == "2") {
					if (player.getMoney() >= 15 && (player.getArmor() == 1 || player.getArmor() == 0)) {
						if (player.getArmor() == 0) {
							player.boostHealth(4);
							player.addArmor(1);
						}
						displayMenu("You purchased Iron Chestplate\n");
						player.subtractMoney(15);
						player.boostHealth(9);
						player.addArmor(1);
					}
					else if (player.getArmor() == 2) {
						displayMenu("You already have this armor.\n");
					}
					else if (player.getArmor() > 2) {
						displayMenu("You have better armor.\n");
					}
					else {
						displayMenu("You don't have enough coins to buy this.\n");
					}
				}
				else if (choice == "3") {
					if (player.getMoney() >= 20 && (player.getArmor() == 1 || player.getArmor() == 2 || player.getArmor() == 0)) {
						if (player.getArmor() == 0) {
							player.boostHealth(8);
							player.addArmor(3);
						}
						else if (player.getArmor() == 1) {
							player.boostHealth(5);
							player.addArmor(2);
						}
						else if (player.getArmor() == 2) {
							player.boostHealth(3);
							player.addArmor(1);
						}
						displayMenu("You purchased Full Iron Armor\n");
						player.subtractMoney(20);
						player.boostHealth(14);
						player.addArmor(1);
					}
					else if (player.getArmor() == 3) {
						displayMenu("You already have this armor.\n");
					}
					else if (player.getArmor() > 3) {
						displayMenu("You have better armor.\n");
					}
					else {
						displayMenu("You don't have enough coins to buy this.\n");
					}
				}
				else if (choice == "4") {
					if (player.getMoney() >= 20 && (player.getArmor() == 1 || player.getArmor() == 2 || player.getArmor() == 3 || player.getArmor() == 0)) {
						if (player.getArmor() == 0) {
							player.boostHealth(8);
							player.addArmor(2);
						}
						else if (player.getArmor() == 1) {
							player.boostHealth(5);
							player.addArmor(1);
						}
						else if (player.getArmor() == 2) {
							player.boostHealth(3);
							player.addArmor(1);
						}
						displayMenu("You purchased the Spiked Chestplate\n");
						player.subtractMoney(20);
						player.boostHealth(12);
						player.boostStrength(2);
						player.addArmor(1);
					}
					else if (player.getArmor() == 4) {
						displayMenu("You already have this armor.\n");
					}
					else if (player.getArmor() > 4) {
						displayMenu("You have better armor.\n");
					}
					else {
						displayMenu("You don't have enough coins to buy this.\n");
					}
				}
				else if (choice == "5") {
					done4 = true;
				}
			}
		}
		else if (choice == "3") {
			done = true;
		}
	}
}

void Shop::displayMenu(std::string menu) {
	std::cout << menu;
}
