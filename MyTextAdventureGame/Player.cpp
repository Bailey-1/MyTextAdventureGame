#include "Player.h"
#include <iostream>
#include <string>

std::string Player::getName(void) { return m_name; }
void Player::setName(std::string name) { m_name = name; }
int Player::getHealth(void) { return m_health; }
void Player::setHealth(int health) { m_health = health; }
int Player::getGold(void) { return m_gold; }
void Player::setGold(int gold) { m_gold = gold; }

std::string Player::getLocationName(void) { return m_location.getName(); }
std::string Player::getLocationDescription(void) { return m_location.getDescription(); }
void Player::setLocation(Tile location) { m_location = location; }

void Player::stats(void)
{
	std::cout << "==================================================" << std::endl;
	std::cout << "                  Player Stats:                   " << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Health: " << getHealth() << std::endl;
	std::cout << "Gold: " << getGold () << std::endl;
	std::cout << "==================================================" << std::endl;
}

Player::Player(void)
{
	setName("dave");
	setHealth(100);
	setGold(0);
}