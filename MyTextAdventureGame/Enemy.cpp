#include "Enemy.h"
#include <iostream>
#include <string>

std::string Enemy::getName(void) { return m_name; }
void Enemy::setName(std::string name) { m_name = name; }
int Enemy::getHealth(void) { return m_health; }
void Enemy::setHealth(int health) { m_health = health; }
int Enemy::getGold(void) { return m_gold; }
void Enemy::setGold(int gold) { m_gold = gold; }

int Enemy::getDamage(void) { return m_damage; }
void Enemy::setDamage(int damage) { m_damage = damage; }

Item Enemy::getWeapon(void) { return m_weapon; }
void Enemy::setWeapon(Item weapon) { m_weapon = weapon; }

std::string Enemy::getLocationName(void) { return m_location.getName(); }
std::string Enemy::getLocationDescription(void) { return m_location.getDescription(); }
void Enemy::setLocation(Tile location) { m_location = location; }

Enemy::Enemy(void)
{
	setName("Test");
	setHealth(100);
	setGold(5);
	setDamage(10);
}