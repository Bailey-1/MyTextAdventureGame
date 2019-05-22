#include "Tile.h"
#include <iostream>
#include <string>

std::string Tile::getId(void) { return m_id; }
void Tile::setId(std::string id) { m_name = id; }
std::string Tile::getName(void) { return m_name; }
void Tile::setName(std::string name) { m_name = name; }
std::string Tile::getDescription(void) { return m_description; }
void Tile::setDescription(std::string description) { m_description = description; }

Enemy Tile::getEnemy(void) { return m_enemy; }
void Tile::setEnemy(Enemy baddie) { m_enemy = baddie; }
bool Tile::getIsEnemyAlive(void) { return m_isEnemyAlive; }
void Tile::setIsEnemyAlive(bool isEnemyAlive) { m_isEnemyAlive = isEnemyAlive; }

Item Tile::getItem(void) { return m_item; }
void Tile::setItem(Item item) { m_item = item; }
bool Tile::getItemExist(void) { return m_doesItemExist; }
void Tile::setItemExist(bool doesItemExist) { m_doesItemExist = doesItemExist; }

Tile::Tile(void) {
	//Null
}

Tile::Tile(std::string id, std::string name, std::string description) {
	setId(id);
	setName(name);
	setDescription(description);
}