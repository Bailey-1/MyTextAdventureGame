#pragma once
#include <iostream>
#include <string>

class Game
{
protected:
	void play(std::string map[7][7], int x, int y);
	void playerMove(std::string map[7][7], int x, int y);

	void move();
	void player();
	void inventory();

public:
	void start(void);
};

