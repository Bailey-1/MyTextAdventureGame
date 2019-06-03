#pragma once
#include <iostream>
#include <string>
#include "Tile.h"
#include "Player.h"

class Locations
{
protected:
	
public:
	std::string intro;

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

	Locations(void);
};

