#include <iostream>
#include <string>

#include "Game.h"

int main()
{
	//Define stuff
	int answer;
	bool playGame = true;
	Game game;
	
	while (playGame == true) {
		std::cout << "==================================================" << std::endl;
		std::cout << "               The Adventure Quest                " << std::endl;
		std::cout << "==================================================" << std::endl;
		std::cout << "1. Play" << std::endl;
		std::cout << "2. Leaderboards" << std::endl;
		std::cout << "3. Quit" << std::endl;
		std::cout << "==================================================" << std::endl;
		std::cout << "Answer: ";
		std::cin >> answer;

		switch (answer)
		{
		case 1:
			game.start();
			system("cls");

			break;
		case 2:
			std::cout << "Coming soon" << std::endl;
			break;
		case 3:
			//Quit Game
			playGame = false;
			break;
		default:
			std::cout << "Invalid selection - Please try again" << std::endl;
		}
	}

	

	return 0;
}
