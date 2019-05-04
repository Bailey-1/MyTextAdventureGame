#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

#include "Game.h"
#include "Player.h"

void Game::start(void)
{
	int x, y;
	char map[3][4] =
	{
		{'A','B','C','D'},
		{'E','F','G','H'},
		{'I','J','K','L'}
	};

	x = 0;
	y = 0;

	play(map, x, y);
}

void Game::play(char map[3][4], int x, int y)
{
	Player player;
	player.stats();


	std::string answer;

	bool isRunning = true;
	while (isRunning == true)
	{
		std::cout << "What do you do?" << std::endl;
		std::cin >> answer;

		std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
		std::cout << answer;
		/*
		if (answer == "w" || answer == "A" || answer == "s" || answer == "d")
		{
			char answerChar = answer[0];
			playerMove(map, x, y, answerChar);
		}
		*/
	}
}

void Game::playerMove(char map[3][4], int x, int y, char input)
{
	int error = 0;

	std::cout << "You are currently at location " << map[y][x];


	switch (input)
	{
	case 'w':
		y = y - 1;
		break;
	case 's':
		y = y + 1;
		break;
	case 'd':
		x = x + 1;
		break;
	case 'a':
		x = x - 1;
		break;
	case '\n':
		break;
	default:
		error = 1;
		break;

	}

	if (x < 0 || y < 0 || x >(4 - 1) || y >(3 - 1))
	{
		x = (x > (4 - 1)) ? (4 - 1) : x;
		x = (x < 0) ? 0 : x;
		y = (y > (3 - 1)) ? (3 - 1) : y;
		y = (y < 0) ? 0 : y;
		error = 1;
	}

	if (error == 1)
		std::cout << "YOU CAN'T GO THAT WAY!" << std::endl;

	play(map, x, y);
}
