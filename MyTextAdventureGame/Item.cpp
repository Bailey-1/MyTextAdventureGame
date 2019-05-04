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