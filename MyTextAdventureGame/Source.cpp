#include <cstdlib>
#include <iostream>

void playerMove(char[3][4], int, int);
void clrscr();

int main()
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

	std::cout << "Use 'w', 'a', 's', 'd' to move around the array of letters";
	std::cout << std::endl << std::endl;

	playerMove(map, x, y);

	return 0;
}

void playerMove(char map[3][4], int x, int y)
{
	char input;
	int error = 0;

	std::cout << "You are currently at location " << map[y][x];
	std::cout << std::endl << "Enter a direction of movement." << std::endl;
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

	clrscr();

	if (error == 1)
		std::cout << "YOU CAN'T GO THAT WAY!" << std::endl;

	playerMove(map, x, y);
}

void clrscr()
{
	system("cls"); //clear for mac

	return;
}
