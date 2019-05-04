#include "Tile.h"
#include <iostream>
#include <string>

std::string Tile::getId(void) { return m_id; }
void Tile::setId(std::string id) { m_name = id; }
std::string Tile::getName(void) { return m_name; }
void Tile::setName(std::string name) { m_name = name; }
std::string Tile::getDescription(void) { return m_description; }
void Tile::setDescription(std::string description) { m_description = description; }
