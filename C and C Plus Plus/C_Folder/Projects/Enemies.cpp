#include "pch.h"
#include "Enemies.h"

Enemies::Enemies() {
	//default constructor
}

Enemies::Enemies(std::string name, int health, int strength, int level) {
	this->name = name;
	this->health = health;
	this->strength = strength;
	this->level = level;
}

Enemies::Enemies(std::string name, int level) {
	this->name = name;
	this->level = level;
}

std::string Enemies::getEnemyName() {
	return name;
}

void Enemies::setEnemyName(std::string name) {
	this->name = name;
}

int Enemies::getEnemyHealth() {
	return health;
}

void Enemies::setEnemyHealth(int health) {
	this->health = health;
}

int Enemies::getEnemyStrength() {
	return strength;
}

void Enemies::setEnemyStrength(int strength) {
	this->strength = strength;
}

int Enemies::getEnemyLevel() {
	return level;
}

void Enemies::setEnemyLevel(int level) {
	this->level = level;
}

void Enemies::decreaseEnemyHealth(int health) {
	this->health -= health;
}