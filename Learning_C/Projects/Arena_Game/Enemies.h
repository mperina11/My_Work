#ifndef ENEMIES_H
#define ENEMIES_H

#include <string>
#include <iostream>

#include <stdlib.h>
#include <time.h>
#include <vector>

class Enemies {
protected:
	std::string name;
	int health;
	int strength;
	int level;
public:
	Enemies();
	Enemies(std::string name, int health, int strength, int level);
	Enemies(std::string name, int level);
	std::string getEnemyName();
	void setEnemyName(std::string name);
	int getEnemyHealth();
	void setEnemyHealth(int health);
	int getEnemyStrength();
	void setEnemyStrength(int strength);
	int getEnemyLevel();
	void setEnemyLevel(int level);
	void decreaseEnemyHealth(int health);
};

#endif

