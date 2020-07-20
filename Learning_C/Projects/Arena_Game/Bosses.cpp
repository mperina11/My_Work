#include "pch.h"
#include "Bosses.h"


Bosses::Bosses(std::string bossName, int bossHealth, int bossStrength, int bossLevel) {
	this->health = 200;
	this->level = 6;
	this->name = "Champion";
	this->strength = 20;
}

std::string Bosses::getBossName() {
	return name;
}

void Bosses::setBossName(std::string bossName) {
	this->name = bossName;
}

int Bosses::getBossHealth() {
	return health;
}
void Bosses::setBossHealth(int bossHealth) {
	this->health = bossHealth;
}

int Bosses::getBossStrength() {
	return strength;
}

void Bosses::setBossStength(int bossStrength) {
	this->strength = bossStrength;
}

int Bosses::getBossLevel() {
	return level;
}

void Bosses::setBosslevel(int bossLevel) {
	this->level = bossLevel;
}

void Bosses::decreaseBossHealth(int bossHealth) {
	this->health -= bossHealth;
}

void Bosses::getBossStats() {
	std::cout << "Name: " << getBossName() << std::endl << "Health: " << getBossHealth() << std::endl;
}
