#pragma once
#include <iostream>
#include <string>
#include "Tile.h"

class Player
{
protected:
	std::string m_name;
	int m_health;
	int m_gold;
	Tile m_location;

public:
	std::string getName(void);
	void setName(std::string);
	int getHealth(void);
	void setHealth(int);
	int getGold(void);
	void setGold(int);

	std::string getLocationName(void);
	std::string getLocationDescription(void);
	void setLocation(Tile);

	void stats(void);

	Player(void);
};

