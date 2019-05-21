#pragma once
#include <iostream>
#include <string>
#include "Tile.h"
#include "Item.h"
#include "Enemy.h"

class Player
{
protected:
	std::string m_name;
	int m_health;
	int m_gold;
	Tile m_location;
	Item m_weapon;

public:
	std::string getName(void);
	void setName(std::string);
	int getHealth(void);
	void setHealth(int);
	int getGold(void);
	void setGold(int);

	Enemy getEnemy(void);
	void setEnemy(Enemy);

	int Battle(Enemy);

	Item getWeapon(void);
	void setWeapon(Item);

	std::string getLocationName(void);
	std::string getLocationDescription(void);
	void setLocation(Tile);

	void stats(void);

	Player(void);
};

