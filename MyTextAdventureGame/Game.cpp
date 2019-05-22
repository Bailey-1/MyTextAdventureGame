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
	intro();
	Tile A("A", "A Tile", "A tile map thing");

	Player player;
	std::cout << "What is the name of your hero? ";
	std::string name;
	std::cin >> name;
	player.setName(name);
	player.setLocation(A);
	player.stats();

	std::cout << " " << std::endl;
	system("pause");
	system("cls");

	std::string map[7][7] =
	{
		{"AAA","XXX","BBB","   ","CCC","XXX","DDD"},
		{"   ","   ","   ","   ","   ","   ","   "},
		{"EEE","XXX","FFF","XXX","GGG","   ","HHH"},
		{"   ","   ","   ","   ","XXX","   ","   "},
		{"III","   ","JJJ","XXX","KKK","   ","LLL"},
		{"   ","   ","XXX","   ","   ","   ","XXX"},
		{"MMM","   ","NNN","   ","OOO","   ","PPP"}
	};

	/*
	std::string map[7][7] =
	{
		{"North-West","XXX","BBB","   ","CCC","XXX","North-East"},
		{"   ","   ","   ","   ","   ","   ","   "},
		{"EEE","XXX","Beginning","XXX","GGG","   ","HHH"},
		{"   ","   ","   ","   ","XXX","   ","   "},
		{"III","   ","JJJ","XXX","KKK","   ","LLL"},
		{"   ","   ","XXX","   ","   ","   ","XXX"},
		{"South-West","   ","NNN","   ","OOO","   ","South-East"}
	};
	*/

	player.setX(0);
	player.setY(0);

	play(map, player);
}

void Game::play(std::string map[7][7], Player player)
{
	int answer;
	std::cout << "Current Location: " << map[player.getY()][player.getX()] << std::endl;
	std::cout << "Location Name: " << player.getLocationName() << std::endl;
	std::cout << "Location Description: " << player.getLocationDescription() << std::endl;

	std::cout << " " << std::endl;
	std::cout << "What do you do?" << std::endl;

	std::cout << "[1] Move" << std::endl;
	std::cout << "[2] Player" << std::endl;
	std::cout << "[3] Inventory" << std::endl;
	std::cout << "[4] Interact With Location" << std::endl;
	std::cout << "[5] Help" << std::endl;
	std::cout << "Choice: ";
	std::cin >> answer;

	switch (answer)
	{
		case 1:
			system("cls");
			playerMove(map, player);
			break;
		case 2:
			std::cout << "Player" << std::endl;
			break;
		case 3:
			std::cout << "Inventory" << std::endl;
			break;
		case 4:
			std::cout << "Interact With Location" << std::endl;
			break;
		case 5:
			std::cout << "Help" << std::endl;
			break;

		default:
			std::cout << "INVALID OPTION: Please try again!" << std::endl;
			system("pause");
			
			play(map, player);
			break;
	}
}

void Game::playerMove(std::string map[7][7], Player player)
{
	int error = 0;
	char input;

	int x = player.getX();
	int y = player.getY();

	//std::cout << "You are currently at location " << map[y][x] << std::endl;

	std::cout << "Which direction do you want to go?" << std::endl;
	std::cout << "[N] North" << std::endl;
	std::cout << "[E] East" << std::endl;
	std::cout << "[S] South" << std::endl;
	std::cout << "[W] West" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "[Q] Quit" << std::endl;
	std::cin >> input;

	system("cls");

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
	{
		std::cout << "==========================" << std::endl;
		std::cout << "= YOU CAN'T GO THAT WAY! =" << std::endl;
		std::cout << "==========================" << std::endl;
	}
	else
	{
		player.setX(x);
		player.setY(y);
	}

	//std::cout << "You are at " << map[y][x] << std::endl;
	play(map, player);
}

/*
void Game::move()
{

}
*/

void Game::player()
{

}

void Game::inventory()
{

}

void Game::intro()
{
	std::cout << "The Beginning:" << std::endl;
	std::cout << "What the fuck did you just fucking say about me, you little bitch? I'll have you know I graduated top of my class in the Navy Seals, and I've been involved in numerous secret raids on Al-Quaeda, and I have over 300 confirmed kills." << std::endl;
	std::cout << " " << std::endl;
	system("pause");
}