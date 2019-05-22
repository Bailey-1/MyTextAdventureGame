#pragma once
#include <iostream>
#include <string>
#include "Enemy.h"
#include "Item.h"

class Tile
{
protected:
	std::string m_id;
	std::string m_name;
	std::string m_description;
	Enemy m_enemy;
	bool m_isEnemyAlive;

	Item m_item;
	bool m_doesItemExist;

public:
	std::string getId(void);
	void setId(std::string name);
	std::string getName(void);
	void setName(std::string name);
	std::string getDescription(void);
	void setDescription(std::string m_Name);

	Enemy getEnemy(void);
	void setEnemy(Enemy);
	bool getIsEnemyAlive(void);
	void setIsEnemyAlive(bool);

	Item getItem(void);
	void setItem(Item);
	bool getItemExist(void);
	void setItemExist(bool);

	Tile(void);
	Tile(std::string, std::string, std::string);
};

