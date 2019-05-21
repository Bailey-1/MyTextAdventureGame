#pragma once
#include <iostream>
#include <string>

class Game
{
protected:
	void play(char map[3][4], int x, int y);
	void playerMove(char map[3][4], int x, int y);

	void move();
	void player();
	void inventory();

	void battle();


public:
	void start(void);
};

