#pragma once
#include <iostream>
#include <string>
#include "Tile.h"
#include "Player.h"
#include "ValidItems.h"

class ValidLocations
{
protected:
	ValidItems validItems;
public:
	std::string intro;
	std::string introContinued;

	Tile A;
	Tile B;
	Tile C;
	Tile D;
	Tile E;
	Tile F;
	Tile G;
	Tile H;
	Tile I;
	Tile J;
	Tile K;
	Tile L;
	Tile M;
	Tile N;
	Tile O;
	Tile P;

	void update(std::string map[7][7], Player);

	ValidLocations(void);
};

