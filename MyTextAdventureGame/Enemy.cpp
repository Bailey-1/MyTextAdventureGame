#include "Enemy.h"
#include <iostream>
#include <string>

std::string Enemy::getName(void) { return m_name; }
void Enemy::setName(std::string name) { m_name = name; }
std::string Enemy::getPhrase(void) { return m_phrase; }
void Enemy::setPhrase(std::string phrase) { m_phrase = phrase; }
std::string Enemy::getKillPhrase(void) { return m_killPhrase; }
void Enemy::setKillPhrase(std::string killPhrase) { m_killPhrase = killPhrase; }
std::string Enemy::getDeathPhrase(void) { return m_deathPhrase; }
void Enemy::setDeathPhrase(std::string deathPhrase) { m_deathPhrase = deathPhrase; }

int Enemy::getHealth(void) { return m_health; }
void Enemy::setHealth(int health) { m_health = health; }
int Enemy::getGold(void) { return m_gold; }
void Enemy::setGold(int gold) { m_gold = gold; }

int Enemy::getDamage(void) { return m_damage; }
void Enemy::setDamage(int damage) { m_damage = damage; }

Item Enemy::getWeapon(void) { return m_weapon; }
void Enemy::setWeapon(Item weapon) { m_weapon = weapon; }

void Enemy::stats(void) {
	std::cout << "==================================================" << std::endl;
	std::cout << "                   Enemy Stats:                   " << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Health: " << getHealth() << std::endl;
	std::cout << "==================================================" << std::endl;
}

Enemy::Enemy(void)
{
	setName("Test");
	setHealth(100);
	setGold(5);
	setDamage(10);
}
