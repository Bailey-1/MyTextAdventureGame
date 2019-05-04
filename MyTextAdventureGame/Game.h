#pragma once
#include <iostream>
#include <string>

class Game
{
protected:
	void play(char map[3][4], int x, int y);
	void playerMove(char map[3][4], int x, int y, char );

public:
	void start(void);
};

