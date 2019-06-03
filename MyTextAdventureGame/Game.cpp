#include <cstdlib>
#include <iostream>
#include <string>

#include "Game.h"
#include "Player.h"
#include "Tile.h"
#include "ValidLocations.h"
#include "ValidItems.h"

void Game::start(void)
{
	intro();

	std::string map[7][7] =
	{
		{"A","X","B"," ","C","X","D"},
		{" "," "," "," "," "," "," "},
		{"E","X","F","X","G"," ","H"},
		{" "," "," "," ","X"," "," "},
		{"I"," ","J","X","K"," ","L"},
		{" "," ","X"," "," "," ","X"},
		{"M"," ","N"," ","O"," ","P"}
	};

	//Player Setup
	Player player;
	std::cout << "What is the name of your hero? ";
	std::string name;
	std::cin >> name;
	player.setName(name);

	Item items[5];
	player.inventory.setItems(*items);
	player.inventory.setSize(5);
	
	player.setX(2);
	player.setY(2);
	player.m_currentLocation = validLocations.F;

	player.setHealth(100);
	player.setGold(50);
	player.setLevel(1);
	player.setWeapon(validItems.smallKnife);
	player.setWeapon(validItems.smallKnife);
	player.inventory.pickupItem(validItems.smallKnife);

	player.stats();

	std::cout << " " << std::endl;
	system("pause");

	play(map, player);
}

void Game::play(std::string map[7][7], Player player)
{
	char answer;
	system("cls");
	std::cout << "Current Location: " << map[player.getY()][player.getX()] << std::endl;
	//std::cout << "Location ID: "<< std::endl;
	std::cout << "Location Name: " << player.m_currentLocation.getName() << std::endl;
	std::cout << "Location Description: " << player.m_currentLocation.getDescription() << std::endl;

	std::cout << "Enemy" << std::endl;
	std::cout << "IsEnemyAlive " << player.m_currentLocation.getIsEnemyAlive() << std::endl;
	std::cout << "Enemy " << player.m_currentLocation.getEnemy().getName() << std::endl;

	std::cout << " " << std::endl;

	if (player.m_currentLocation.getIsEnemyAlive() == true)
	{
		bool isEnemyDead = player.Battle(player.m_currentLocation.getEnemy());
		
		if (isEnemyDead == true)
		{
			player.m_currentLocation.setIsEnemyAlive(false);
			std::cout << "Well Done. You killed the "<< player.m_currentLocation.getEnemy().getName() << "."<< std::endl;
			

			validLocations.A = player.m_currentLocation;

			system("pause");
			play(map, player);
		}
		else
		{
			std::cout << "YOU DIED" << std::endl;
			player.finalStats(player.m_currentLocation.getEnemy());
			system("pause");
			return;
		}
	}
	else
	{
		std::cout << "What do you do?" << std::endl;
		std::cout << "[1] Move" << std::endl;
		std::cout << "[2] Player" << std::endl;
		std::cout << "[3] Inventory" << std::endl;
		std::cout << "[4] Interact With Location" << std::endl;
		std::cout << "[5] Search Room" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "[6] Help" << std::endl;
		std::cout << "Choice: ";
		std::cin >> answer;

		switch (answer)
		{
		case '1':
			system("cls");
			playerMove(map, player);
			break;
		case '2':
			system("cls");
			playerOptions(map, player);
			break;
		case '3':
			system("cls");
			std::cout << "Inventory" << std::endl;
			inventory(map, player);
			break;
		case '4':
			system("cls");
			std::cout << "Interact With Location" << std::endl;
			interact(map, player);
			break;
		case '5':
			system("cls");
			std::cout << "Search Location" << std::endl;
			searchRoom(map, player);
			break;
		case '6':
			std::cout << "Help" << std::endl;
			break;

		default:
			std::cout << "INVALID OPTION: Please try again!" << std::endl;
			system("pause");

			play(map, player);
			break;
		}
	}

	if (validLocations.A.getIsEnemyAlive() == false 
		&& validLocations.D.getIsEnemyAlive() == false
		&& validLocations.M.getIsEnemyAlive() == false
		&& validLocations.P.getIsEnemyAlive() == false)
	{
		system("cls");

		/*
			You have to replace every "\" with "\\" for it to ascii to
			work cause the compiler skips "\" cause like "\n" or something
		*/
		
		std::cout << "__  __                 _                       _       __    _                               " << std::endl;
		std::cout << "\\ \\/ /  ____   __  __ ( )   _____  ___        | |     / /   (_)   ____    ____   ___    _____" << std::endl;
		std::cout << " \\  /  / __ \\ / / / / |/   / ___/ / _ \\       | | /| / /   / /   / __ \\  / __ \\ / _ \\  / ___/" << std::endl;
		std::cout << " / /  / /_/ // /_/ /      / /    /  __/       | |/ |/ /   / /   / / / / / / / //  __/ / /    " << std::endl;
		std::cout << "/_/   \\____/ \\__,_/      /_/     \\___/        |__/|__/   /_/   /_/ /_/ /_/ /_/ \\___/ /_/     " << std::endl;

		player.winStats();

		return;
	}
}

void Game::playerMove(std::string map[7][7], Player player)
{
	validLocations.update(map, player);
	int error = 0;
	char input;

	Tile prevLocation = player.m_currentLocation;

	int y = player.getY();
	int x = player.getX();
	int testY = player.getY();
	int testX = player.getX();

	std::cout << "Current Location: " << map[player.getY()][player.getX()] << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Which direction do you want to go?" << std::endl;
	std::cout << "[W] North" << std::endl;
	std::cout << "[D] East" << std::endl;
	std::cout << "[S] South" << std::endl;
	std::cout << "[A] West" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "[Q] Quit" << std::endl;
	std::cin >> input;

	system("cls");

	switch (input)
	{
	case 'w':
		y = y - 2;
		if (map[player.getY() - 1][player.getX()] == "X")
		{
			std::cout << "A large wall blocks your way." << std::endl;
			error = 1;
		}
		break;
	case 's':
		y = y + 2;
		if (map[player.getY() + 1][player.getX()] == "X")
		{
			std::cout << "A large wall blocks your way." << std::endl;
			error = 1;
		}
		break;
	case 'd':
		x = x + 2;
		if (map[player.getY()][player.getX() + 1] == "X")
		{
			std::cout << "A large wall blocks your way." << std::endl;
			error = 1;
		}
		break;
	case 'a':
		x = x - 2;
		if (map[player.getY()][player.getX() - 1] == "X")
		{
			std::cout << "A large wall blocks your way." << std::endl;
			error = 1;
		}
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
		system("pause");
	}
	else
	{
		player.setX(x);
		player.setY(y);


		//Probably a nicer way to do this but idk
		if (map[player.getY()][player.getX()] == "A")
		{
			player.m_currentLocation = validLocations.A;
		}
		else if (map[player.getY()][player.getX()] == "B")
		{
			player.m_currentLocation = validLocations.B;
		}
		else if (map[player.getY()][player.getX()] == "C")
		{
			player.m_currentLocation = validLocations.C;
		}
		else if (map[player.getY()][player.getX()] == "D")
		{
			player.m_currentLocation = validLocations.D;
		}
		else if (map[player.getY()][player.getX()] == "E")
		{
			player.m_currentLocation = validLocations.E;
		}
		else if (map[player.getY()][player.getX()] == "F")
		{
			player.m_currentLocation = validLocations.F;
		}
		else if (map[player.getY()][player.getX()] == "G")
		{
			player.m_currentLocation = validLocations.G;
		}
		else if (map[player.getY()][player.getX()] == "H")
		{
			player.m_currentLocation = validLocations.H;
		}
		else if (map[player.getY()][player.getX()] == "I")
		{
			player.m_currentLocation = validLocations.I;
		}
		else if (map[player.getY()][player.getX()] == "J")
		{
			player.m_currentLocation = validLocations.J;
		}
		else if (map[player.getY()][player.getX()] == "K")
		{
			player.m_currentLocation = validLocations.K;
		}
		else if (map[player.getY()][player.getX()] == "L")
		{
			player.m_currentLocation = validLocations.L;
		}
		else if (map[player.getY()][player.getX()] == "M")
		{
			player.m_currentLocation = validLocations.M;
		}
		else if (map[player.getY()][player.getX()] == "N")
		{
			player.m_currentLocation = validLocations.N;
		}
		else if (map[player.getY()][player.getX()] == "O")
		{
			player.m_currentLocation = validLocations.O;
		}
		else if (map[player.getY()][player.getX()] == "P")
		{
			player.m_currentLocation = validLocations.P;
		}
		//gross isnt it.
	}

	if (player.m_currentLocation.getName() != player.m_prevLocation.getName())
	{
		player.m_prevLocation = prevLocation;
	}
	//std::cout << "You are at " << map[y][x] << std::endl;
	play(map, player);
}

void Game::playerOptions(std::string map[7][7], Player player)
{
	std::string newName;
	//Where the player can chose to do things such as view information about them? Maybe remove this?
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "[1] View Stats" << std::endl;
	std::cout << "[2] Change Name" << std::endl;
	std::cout << "[3] Save Game" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "[Q] Quit" << std::endl;
	char answer;
	std::cin >> answer;

	switch (answer)
	{
	case '1':
		player.stats();
		system("pause");
		break;
	case '2':
		std::cout << "You are currently called \"" << player.getName() << "\"" << std::endl;
		std::cout << "What would you like to be called?" << std::endl;
		std::cin >> newName;
		player.setName(newName);

		std::cout << " " << std::endl;
		std::cout << "You are now called \"" << player.getName() << "\"" << std::endl;
		std::cout << " " << std::endl;
		player.stats();
		system("pause");
		break;
	case '3':
		std::cout << "Coming soon!" << std::endl;
		system("pause");
		break;
	case 'q':
		break;
	default:
		std::cout << "Invalid Option" << std::endl;
		std::cout << "Please try again" << std::endl;
		system("pause");
		playerOptions(map, player);

	}
	play(map, player);
}

void Game::inventory(std::string map[7][7], Player player)
{
	//Where the player can chose to do things such as view information about them? Maybe remove this?
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "[1] View Inventory" << std::endl;
	std::cout << "[2] View Information about item" << std::endl;
	std::cout << "[3] Move items" << std::endl;
	std::cout << "[4] Remove Item" << std::endl;
	std::cout << "[5] Set Weapon" << std::endl;

	std::cout << " " << std::endl;
	std::cout << "[Q] Quit" << std::endl;
	char answer;
	std::cin >> answer;

	int itemchoice;
	switch (answer)
	{
	case '1':
		std::cout << "View Inventory" << std::endl;
		player.inventory.viewInventory();
		system("pause");
		break;
	case '2':
		std::cout << "Information about Item" << std::endl;
		for (int i = 0; i <= 4; i++)
		{
			std::cout << "[" << i + 1 << "] " << player.inventory.getItem(i).getName() << std::endl;
		}
		std::cout << "What item do you want to know more about?" << std::endl;
		std::cin >> itemchoice;
		itemchoice--; // ARRAYS START AT 0;

		if (player.inventory.getItem(itemchoice).getName() != "")
		{
			player.inventory.getItem(itemchoice).stats();
			system("pause");
		}
		else
		{
			std::cout << "Invalid Option" << std::endl;
			system("pause");
		}
		break;
	case '3':
		std::cout << "Move Items" << std::endl;
		player.inventory.viewInventory();

		std::cout << "First Item: " << std::endl;
		int fItem;
		std::cin >> fItem;

		std::cout << "Second Item: " << std::endl;
		int sItem;
		std::cin >> sItem;

		player.inventory.swapItem(fItem - 1, sItem - 1);

		break;
	case '4':
		//Null

		break;
	case '5':
		std::cout << "Set Main Weapon" << std::endl;
		player.inventory.viewInventory();

		std::cout << "Choice: " << std::endl;
		int weaponChoice;
		std::cin >> weaponChoice;
		weaponChoice--; 

		if (player.inventory.getItem(weaponChoice).getType() == "Weapon")
		{
			player.setWeapon(player.inventory.getItem(weaponChoice - 1));
			
			std::cout << "Successfully Set Main Weapon" << std::endl;
			system("pause");
		}
		else
		{
			std::cout << "INVALID CHOICE" << std::endl;
			std::cout << "Item needs to be type \"Weapon\"" << std::endl;
			system("pause");
		}

		break;
	case 'q':
		break;
	default:
		std::cout << "Invalid Option" << std::endl;
		std::cout << "Please try again" << std::endl;
		system("pause");
		playerOptions(map, player);

	}
	play(map, player);
}

void Game::interact(std::string map[7][7], Player player)
{
	//Where the player will bee able to chose to interact with the room:
	//- Pickup items in room.
	//- Start a battle with a enermy.
	//- Read writing on a wall or in a diary/book.?

	system("cls");
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "[1] Search Room" << std::endl;
	std::cout << "[2]" << std::endl;
	std::cout << "[3]" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "[Q] Quit" << std::endl;
	char answer;
	std::cin >> answer;

	switch (answer)
	{
	case '1':
		if (player.m_currentLocation.getItemExist() == true)
		{
			std::cout << "You begin to search the room. After sometime, you find: " << std::endl;
			std::cout << "[1] " << player.m_currentLocation.getItem().getName() << std::endl;
			std::cout << " " << std::endl;

		}
		break;
	case '2':
		//Null
		break;
	case '3':
		//Null
		break;
	case 'q':
		break;
	default:
		std::cout << "Invalid Option" << std::endl;
		std::cout << "Please try again" << std::endl;
		system("pause");
		playerOptions(map, player);

	}
	play(map, player);
}

void Game::searchRoom(std::string map[7][7], Player player)
{
	std::cout << "Search Room" << std::endl;
	if (player.m_currentLocation.getItemExist() == true)
	{
		std::cout << "You spend a little while looking around the area, when you suddenly find:" << std::endl;

		player.m_currentLocation.getItem().stats();
		system("pause");
	}
	else
	{
		std::cout << "You were unable to find anything in this room." << std::endl;
		std::cout << "Maybe theres something good in another?" << std::endl;
		system("pause");
	}
	play(map, player);
}

void Game::help(std::string map[7][7], Player player)
{
	//Display information about how the game works etc.
	system("cls");
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "[1] General" << std::endl;
	std::cout << "[2] Movement" << std::endl;
	std::cout << "[3] Combat" << std::endl;
	std::cout << "[4] Enemies" << std::endl;
	std::cout << "[5] Items" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "[Q] Quit" << std::endl;
	char answer;
	std::cin >> answer;

	switch (answer)
	{
	case '1':
		//Null
		break;
	case '2':
		//Null
		break;
	case '3':
		//Null
		break;
	case '4':
		//Null
		break;
	case '5':
		//Null
		break;
	case 'q':
		break;
	default:
		std::cout << "Invalid Option" << std::endl;
		std::cout << "Please try again" << std::endl;
		system("pause");
		help(map, player);

	}
	play(map, player);
}

void Game::intro()
{
	std::cout << "The Beginning:" << std::endl;
	std::cout << validLocations.intro << std::endl;
	system("pause");
}
