#include "pch.h"
#include "Player.h"

Player::Player() {
	//default constructor
}

Player::Player(std::string name) {
	this->name = name;
	this->level = 0;
	this->maxHealth = 100;
	this->health = 100;
	this->strength = 50;
	this->money = 0;
	this->weapon = 0;
	this->armor = 0;
}

Player::Player(std::string name, int level, int maxHealth, int health, int strength, int money, int weapon, int armor) {
	this->name = name;
	this->level = level;
	this->maxHealth = maxHealth;
	this->health = health;
	this->strength = strength;
	this->money = money;
	this->weapon = weapon;
	this->armor = armor;
}

std::string Player::getName() {
	return name;
}

void Player::setName(std::string name) {
	this->name = name;
}

int Player::getLevel() {
	return level;
}

void Player::setLevel(int level) {
	this->level = level;
}

void Player::addLevel(int level) {
	this->level += level;
}

int Player::getMaxHealth() {
	return maxHealth;
}

void Player::setMaxHealth(int maxHealth) {
	this->maxHealth = maxHealth;
}

int Player::getHealth() {
	return health;
}

void Player::setHealth(int health) {
	this->health = health;
}

int Player::getStrength() {
	return strength;
}

void Player::setStrength(int strength) {
	this->strength;
}

int Player::getMoney() {
	return money;
}

void Player::setMoney(int money) {
	this->money = money;
}

void Player::addMoney(int coins) {
	this->money += coins;
}

void Player::subtractMoney(int coins) {
	this->money -= coins;
}

void Player::restoreHealth(int health) {
	this->health += health;
}

void Player::boostHealth(int health) {
	this->health += health;
}

void Player::boostStrength(int strength) {
	this->strength += strength;
}

void Player::decreaseHealth(int health) {
	this->health -= health;
}

int Player::getWeapon() {
	return weapon;
}

void Player::setWeapon(int weapon) {
	this->weapon = weapon;
}
void Player::addWeapon(int weapon) {
	this->weapon += weapon;
}
int Player::getArmor() {
	return armor;
}
void Player::setArmor(int armor) {
	this->armor = armor;
}
void Player::addArmor(int armor) {
	this->armor += armor;
}

void Player::getPlayerStats() {
	std::cout << "Name: " << getName() << std::endl
		<< "Level: " << getLevel() << std::endl
		<< "Health: " << getHealth() << std::endl
		<< "Strength: " << getStrength() << std::endl
		<< "Coins: " << getMoney() << std::endl;
}
