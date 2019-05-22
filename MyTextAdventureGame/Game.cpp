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

	std::string map[7][7] =
	{
		{"AAA","   ","BBB","   ","CCC","   ","DDD"},
		{"   ","   ","   ","   ","   ","   ","   "},
		{"EEE","   ","FFF","   ","GGG","   ","HHH"},
		{"   ","   ","   ","   ","   ","   ","   "},
		{"III","   ","JJJ","   ","KKK","   ","LLL"},
		{"   ","   ","   ","   ","   ","   ","   "},
		{"MMM","   ","NNN","   ","OOO","   ","PPP"}
	};

	x = 0;
	y = 0;
	play(map, x, y);
}

void Game::play(std::string map[7][7], int x , int y)
{
	int answer;

	std::cout << "Current Location: " << map[y][x] << std::endl;

	std::cout << "What do you do?" << std::endl;

	std::cout << "[1] Move" << std::endl;
	std::cout << "[2] Player" << std::endl;
	std::cout << "[3] Inventory" << std::endl;
	std::cout << "[4] " << std::endl;
	std::cout << "[5] Help" << std::endl;

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

void Game::playerMove(std::string map[7][7], int x, int y)
{
	
	int error = 0;
	char input;

	//std::cout << "You are currently at location " << map[y][x] << std::endl;

	std::cout << "Which direction do you want to go?" << std::endl;
	std::cout << "[N] North" << std::endl;
	std::cout << "[E] East" << std::endl;
	std::cout << "[S] South" << std::endl;
	std::cout << "[W] West" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "[Q] Quit" << std::endl;
	std::cin >> input;

	switch (input)
	{
		case 'w':
			y = y - 2;
			break;
		case 's':
			y = y + 2;
			break;
		case 'd':
			x = x + 2;
			break;
		case 'a':
			x = x - 2;
			break;
		case 'q':
			break;
		case '\n':
			break;
		default:
			error = 1;
		break;
	}

	if (x < 0 || y < 0 || x >(7 - 1) || y >(7 - 1))
	{
		x = (x > (7 - 1)) ? (7 - 1) : x;
		x = (x < 0) ? 0 : x;
		y = (y > (7 - 1)) ? (7 - 1) : y;
		y = (y < 0) ? 0 : y;
		error = 1;
	}

	if (error == 1)
		std::cout << "YOU CAN'T GO THAT WAY!" << std::endl;

	//std::cout << "You are at " << map[y][x] << std::endl;
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
