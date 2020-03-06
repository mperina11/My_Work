#include "pch.h"
#include "BeginnersArena.h"
#include <conio.h>


void BeginnersArena::enterArena(Player player) {
	setDone(false);
	while (!isDone()) {
		displayMenu("1. Fight in the Arena\n"
			"2. Armor/Weapon Shop\n"
			"3. Rest\n"
			"4. View Stats\n"
			"5. Fight Champion\n"
			"6. Exit\n");
		std::string choice = getUserInput("");

		if (choice == "1") {
			//Fight
			fightArena(player);
		}
		else if (choice == "2") {
			//Shop
			shop.enterShop(player);
		}
		else if (choice == "3") {
			//Rest
			arenaRest(player);
		}
		else if (choice == "4") {
			player.getPlayerStats();
		}
		else if (choice == "5") {
			if (player.getLevel() > 4) {
				std::cout << "You have entered the Boss arena...\n";
				//add fight the boss here 
				bossFight(player);
			}
			else {
				std::cout << "You are not not a high enough level to fight a Boss\n";
				std::cout << "You are level " << player.getLevel() << ", a level of 5 or higher is required\n";
			}
		}
		else if (choice == "6") {
			setDone(true);
		}
		else
			displayMenu("You entered the wrong input\n");
	}
}

void BeginnersArena::fightArena(Player& player) {
	int done = false;
	srand(time(NULL));
	int random = rand() % 5;
	Enemies enemy[5];
	enemy[0] = { "Slave", 50, 2, 1 };
	enemy[1] = { "Deserted Warrior", 75, 4, 2 };
	enemy[2] = { "Hound", 50, 5, 3 };
	enemy[3] = { "Deserted Archer", 75, 5, 4 };
	enemy[4] = { "Soldier", 100, 6, 5 };

	std::cout << "You have entered the arena..\n\n";
	std::cout << enemy[random].getEnemyName() << " lvl " << enemy[random].getEnemyLevel() << " is your opponent\n";
	while (!done) {
		srand(time(NULL));
		int random2 = rand() % 9;
		std::cout << "Enemy: " << enemy[random].getEnemyHealth() << std::endl;
		std::cout << "Me: " << player.getHealth() << std::endl;
		int attack;

		clock_t start = clock();

		std::cout << "Enter \"" << random2 << "\" to attack!\n";

		while (!_kbhit()) //Check for keyboard hit
		{
			if (((clock() - start) / CLOCKS_PER_SEC) >= 2)
			{
				player.decreaseHealth(enemy[random].getEnemyStrength());
				std::cout << "You stand and do nothing, you take damage...\n";
				if (player.getHealth() <= 0) {
					std::cout << "You died!\n";
					done = true;
				}
				start = clock();                            //Set new timer
			}
		}
		//Get the input here
		std::cin >> attack;

		if (attack == random2) {
			enemy[random].decreaseEnemyHealth(player.getStrength());
			if (enemy[random].getEnemyHealth() <= 0) {
				std::cout << "You win!\n";
				player.addMoney(enemy[random].getEnemyLevel());
				player.setLevel(player.getLevel() + 1); // will level up once with each win


				x.push_back(enemy[random].getEnemyName());	//print enemies defeated 				
				std::cout << "You have beaten:\n";
				for (auto y : x) {
					std::cout << y << "\n";
				}
				std::cout << "\n"; //just an extra space

				done = true;
			}
		}
		else {
			player.decreaseHealth(enemy[random].getEnemyStrength());
			if (player.getHealth() <= 0) {
				std::cout << "You died!\n";
			}
		}
	}
}

void BeginnersArena::arenaRest(Player& player) {
	displayMenu("You chose to rest in your cell. Some of your health have been restored\n");
	if (player.getHealth() < 100) {
		player.restoreHealth(player.getMaxHealth() - player.getHealth());
	}
	else {
		displayMenu("You health is at MAX.\n");
	}
}

void BeginnersArena::displayMenu(std::string menu) {
	std::cout << menu;
}
void BeginnersArena::bossFight(Player& player) {
	Bosses boss = { "Champion", 200, 20, 6 };

	displayMenu("Fight for your freedom!\n\n");

	std::cout << "Boss: " << boss.getBossHealth() << std::endl;
	std::cout << "Me: " << player.getHealth() << std::endl;

	while (!done) {
		srand(time(NULL));
		int random2 = rand() % 9;
		std::cout << "Enemy: " << boss.getBossHealth() << std::endl;
		std::cout << "Me: " << player.getHealth() << std::endl;

		int attack;

		clock_t start = clock();

		std::cout << "Enter \"" << random2 << "\" to attack!\n";

		while (!_kbhit()) //Check for keyboard hit
		{
			if (((clock() - start) / CLOCKS_PER_SEC) >= 2) // divide by CLOCKS_PER_SEC to get number in seconds.
			{
				player.decreaseHealth(boss.getBossStrength());
				std::cout << "You stand and do nothing, you take damage...\n";
				if (player.getHealth() <= 0) {
					std::cout << "You died!\n";
					done = true;
				}
				start = clock();                            //Set new timer
			}
		}
		//Get the input here
		std::cin >> attack;

		if (attack == random2) {
			boss.decreaseBossHealth(player.getStrength());
			if (boss.getBossHealth() <= 0) {
				std::cout << "You win!\n";
				displayMenu("You've beaten the champion and claimed your freedom!\n");
					displayMenu("Thanks for playing!\n");
				done = true;
			}
		}
		else {
			player.decreaseHealth(boss.getBossStrength());
			if (player.getHealth() <= 0) {
				std::cout << "You died!\n";
			}
		}
	}
}
