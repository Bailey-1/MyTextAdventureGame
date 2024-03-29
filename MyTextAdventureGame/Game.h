#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "ValidLocations.h"
#include "ValidItems.h"

class Game
{
protected:
	void play(std::string map[7][7], Player player);
	void playerMove(std::string map[7][7], Player player);

	void playerOptions(std::string map[7][7], Player player);
	void inventory(std::string map[7][7], Player player);
	void interact(std::string map[7][7], Player player);

	void searchRoom(std::string map[7][7], Player player);

	void help(std::string map[7][7], Player player);
	//std::string map[7][7];

	ValidLocations validLocations;
	ValidItems validItems;

	void intro(void);

public:
	void start(void);
};

