#include <cstdlib>
#include <iostream>
#include <string>

#include "Game.h"
#include "Player.h"

void leaderboards(void);
void credits(void);

int main()
{
	//Define stuff
	char answer;
	bool playGame = true;
	Game game;

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
		case '1':
			game.start();

			break;
		case '2':
			leaderboards();
			system("pause");
			break;
		case '3':
			credits();
			system("pause");
			break;
		case '4':
			playGame = false;
			break;
		case '5':
			std::cout << "__  __                 _                       _       __    _                               " << std::endl;
			std::cout << "\\ \\/ /  ____   __  __ ( )   _____  ___        | |     / /   (_)   ____    ____   ___    _____" << std::endl;
			std::cout << " \\  /  / __ \\ / / / / |/   / ___/ / _ \\       | | /| / /   / /   / __ \\  / __ \\ / _ \\  / ___/" << std::endl;
			std::cout << " / /  / /_/ // /_/ /      / /    /  __/       | |/ |/ /   / /   / / / / / / / //  __/ / /    " << std::endl;
			std::cout << "/_/   \\____/ \\__,_/      /_/     \\___/        |__/|__/   /_/   /_/ /_/ /_/ /_/ \\___/ /_/     " << std::endl;

			system("pause");
			break;

		default:
			std::cout << "Invalid selection - Please try again" << std::endl;
		}
		system("cls");
	}
	return 0;
}

void leaderboards() {
	std::cout << "==================================================" << std::endl;
	std::cout << "               The Adventure Quest                " << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "Leaderboards:\n" << std::endl;
	std::cout << "Coming Soon" << std::endl;
	std::cout << "==================================================" << std::endl;
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
