#ifndef BOSSES_H
#define BOSSES_H
#include <string>
#include <iostream>

#include "Enemies.h"

class Bosses : public Enemies {
public:
	Bosses(std::string bossName, int bossHealth, int bossStrength, int bossLevel);
	std::string getBossName();

	void setBossName(std::string bossName);
	int getBossHealth();
	void setBossHealth(int bossHealth);
	int getBossStrength();
	void setBossStength(int bossStrength);
	int getBossLevel();
	void setBosslevel(int bossLevel);
	void decreaseBossHealth(int bosshealth);
	void getBossStats();

};

#endif
