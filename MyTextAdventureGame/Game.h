#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "Locations.h"

class Game
{
protected:
	void play(std::string map[7][7], Player player);
	void playerMove(std::string map[7][7], Player player);

	void player(void);
	void inventory(void);
	void interact(void);
	void help(void);

	Locations validLocations;

	void intro(void);

public:
	void start(void);
};

