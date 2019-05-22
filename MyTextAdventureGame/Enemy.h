#pragma once
#include <iostream>
#include <string>
#include "Item.h"

class Enemy
{
protected:
	std::string m_name;
	int m_health;
	int m_gold;
	Item m_weapon;
	int m_damage;

public:
	std::string getName(void);
	void setName(std::string);
	int getHealth(void);
	void setHealth(int);
	int getGold(void);
	void setGold(int);

	int getDamage(void);
	void setDamage(int);

	Item getWeapon(void);
	void setWeapon(Item);

	void stats(void);

	Enemy(void);
};

