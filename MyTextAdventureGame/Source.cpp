#include <cstdlib>
#include <iostream>
#include <string>

#include "Game.h"

#include "Player.h"

void credits(void);

int main()
{
	//Define stuff
	int answer;
	bool playGame = true;
	Game game;

	Player player;
	player.setName("Dave");
	player.setHealth(100);
	player.setGold(0);

	Item sword;
	sword.setName("Super Sword");
	sword.setDamage(15);

	player.setWeapon(sword);
	Enemy baddie;
	baddie.setName("Test");
	baddie.setHealth(100);
	baddie.setGold(5);
	baddie.setDamage(10);

	bool isBaddieDead;

	while (playGame == true) {
		std::cout << "==================================================" << std::endl;
		std::cout << "               The Adventure Quest                " << std::endl;
		std::cout << "==================================================" << std::endl;
		std::cout << "1. Play" << std::endl;
		std::cout << "2. Leaderboards" << std::endl;
		std::cout << "3. Credits" << std::endl;
		std::cout << "4. Quit" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "5. Test" << std::endl;
		std::cout << "==================================================" << std::endl;
		std::cout << "Answer: ";
		std::cin >> answer;
		
		system("cls");

		switch (answer)
		{
		case 1:
			game.start();
			
			break;
		case 2:
			std::cout << "Coming soon" << std::endl;
			system("pause");
			break;
		case 3:
			credits();
			system("pause");
			break;
		case 4:
			playGame = false;
			break;
		case 5:
			player.setHealth(10);
			isBaddieDead = player.Battle(baddie);
			std::cout << "IS THE BADDIE DEAD " << isBaddieDead << std::endl;
			system("pause");
			break;

		default:
			std::cout << "Invalid selection - Please try again" << std::endl;
		}
		system("cls");
	}
	return 0;
}

void credits() {
	std::cout << "==================================================" << std::endl;
	std::cout << "               The Adventure Quest                " << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "Credits:" << std::endl;
	std::cout << "Design: Bailey" << std::endl;
	std::cout << "Programming: Bailey" << std::endl;
	std::cout << "Writing: Bailey" << std::endl;
	std::cout << "==================================================" << std::endl;
}