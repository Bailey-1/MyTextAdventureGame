#include "Item.h"
#include <iostream>
#include <string>

std::string Item::getName(void) { return m_name; }
void Item::setName(std::string name) { m_name = name; }
std::string Item::getType(void) { return m_type; }
void Item::setType(std::string type) { m_type = type; }
std::string Item::getDescription(void) { return m_description; }
void Item::setDescription(std::string description) { m_description = description; }

int Item::getDamage(void) { return m_damage; }
void Item::setDamage(int damage) { m_damage = damage; }

int Item::getHealth(void) { return m_health; }
void Item::setHealth(int health) { m_health = health; }

float Item::getXpBonus(void) { return m_xpBonus; }
void Item::setXpBonus(float xp) { m_xpBonus = xp; }

void Item::stats(void)
{
	std::cout << "==================================================" << std::endl;
	std::cout << "                   Item Stats:                   " << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Description: " << m_description << std::endl;
	std::cout << "Type: " << m_type << std::endl;

	if (m_type == "Health")
	{
		std::cout << "Health: " << m_health << std::endl;
	}
	else if (m_type == "XP")
	{
		std::cout << "XP Bonus: " << m_xpBonus << std::endl;
	}
	else if (m_type == "Weapon")
	{
		std::cout << "Damage: " << m_damage << std::endl;
	}

	std::cout << "Type: " << getDamage() << std::endl;
	std::cout << "==================================================" << std::endl;
}