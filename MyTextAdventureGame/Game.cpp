#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

#include "Game.h"
#include "Player.h"
#include "Tile.h"

void Game::start(void)
{
	Tile A("A", "A Tile", "A tile map thing");

	Player player;
	std::cout << "What is the name of your hero? ";
	std::string name;
	std::cin >> name;
	player.setName(name);
	player.setLocation(A);
	player.stats();

	int x, y;
	char map[4][4] =
	{
		{'A','B','C','D'},
		{'E','F','G','H'},
		{'I','J','K','L'},
		{'M','N','O','P'}
	};

	x = 0;
	y = 0;
	play(map, x, y);
}

void Game::play(char map[4][4], int x , int y)
{
	int answer;

	std::cout << map[x][y] << std::endl;

	std::cout << "What do you do?" << std::endl;

	std::cout << "[1] Move" << std::endl;
	std::cout << "[2] Player" << std::endl;
	std::cout << "[3] Inventory" << std::endl;
	std::cout << "[4] " << std::endl;
	std::cout << "[5] Move" << std::endl;

	std::cin >> answer;

	switch (answer)
	{
		case 1:
			playerMove(map, x, y);
			break;
		case 2:
			std::cout << "Player" << std::endl;
			break;
		case 3:
			std::cout << "Inventory" << std::endl;
			break;

		default:
			std::cout << "Suck my ass" << std::endl;
	}
}

void Game::playerMove(char map[4][4], int x, int y)
{
	int error = 0;
	char input;

	std::cout << "You are currently at location " << map[y][x] << std::endl;

	std::cout << "Which direction do you want to go?" << std::endl;
	std::cin >> input; 

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

	std::cout << "You are at " << map[x][y] << std::endl;
	play(map, x, y);
}

void Game::move()
{
	
}

void Game::player()
{

}

void Game::inventory()
{

}