#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {
private:
	std::string name;
	int level;
	int maxHealth;
	int health;
	int strength;
	int money;
	int weapon;
	int armor;
public:
	Player();
	Player(std::string name);
	Player(std::string name, int level, int maxHealth, int health, int strength, int money, int weapon, int armor);
	std::string getName();
	void setName(std::string name);
	int getLevel();
	void setLevel(int level);
	void addLevel(int level);
	int getMaxHealth();
	void setMaxHealth(int maxHealth);
	int getHealth();
	void setHealth(int health);
	int getStrength();
	void setStrength(int strength);
	int getMoney();
	void setMoney(int money);
	void addMoney(int coins);
	void subtractMoney(int coins);
	void getPlayerStats();
	void restoreHealth(int health);
	void boostStrength(int strength);
	void boostHealth(int health);
	void decreaseHealth(int health);
	int getWeapon();
	void setWeapon(int weapon);
	void addWeapon(int weapon);
	int getArmor();
	void setArmor(int armor);
	void addArmor(int armor);
};

#endif



