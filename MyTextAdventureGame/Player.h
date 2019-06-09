#pragma once
#include <iostream>
#include <string>
#include "Tile.h"
#include "Item.h"
#include "Enemy.h"
#include "Inventory.h"

class Player
{
protected:
	std::string m_name;
	int m_health;

	int m_level;
	int m_gold;
	int m_xp;

	Tile m_location;

	Item m_weapon;

	int m_x;
	int m_y;

public:
	std::string getName(void);
	void setName(std::string);
	int getHealth(void);
	void setHealth(int);

	int getLevel(void);
	void setLevel(int);
	int getGold(void);
	void setGold(int);
	int getXp(void);
	void setXp(int);

	int getX(void);
	void setX(int);
	int getY(void);
	void setY(int);

	std::string Battle(Enemy);

	Inventory inventory;

	Item getWeapon(void);
	void setWeapon(Item);

	Tile m_prevLocation;
	Tile m_currentLocation;

	void stats(void);
	void finalStats(Enemy);
	void winStats(void);

	Player(void);
};
