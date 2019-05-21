 #include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string Player::getName(void) { return m_name; }
void Player::setName(std::string name) { m_name = name; }
int Player::getHealth(void) { return m_health; }
void Player::setHealth(int health) { m_health = health; }
int Player::getGold(void) { return m_gold; }
void Player::setGold(int gold) { m_gold = gold; }

Item Player::getWeapon(void) { return m_weapon; }
void Player::setWeapon(Item weapon) { m_weapon = weapon; }

std::string Player::getLocationName(void) { return m_location.getName(); }
std::string Player::getLocationDescription(void) { return m_location.getDescription(); }
void Player::setLocation(Tile location) { m_location = location; }

void Player::stats(void)
{
	std::cout << "==================================================" << std::endl;
	std::cout << "                  Player Stats:                   " << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Health: " << getHealth() << std::endl;
	std::cout << "Gold: " << getGold () << std::endl;
	std::cout << "Location: " << getLocationName() << std::endl;
	std::cout << "==================================================" << std::endl;
}

Player::Player(void)
{
	setHealth(100);
	setGold(0);
}

int Player::Battle(Enemy baddie)
{
	int run = 1;
	std::cout << "==================================================" << std::endl;
	std::cout << "                      Battle:                     " << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Health: " << getHealth() << std::endl;
	std::cout << "Damage: " << m_weapon.getDamage() << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "                        VS                        " << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "Name: " << baddie.getName() << std::endl;
	std::cout << "Health: " << baddie.getHealth() << std::endl;
	std::cout << "Damage: " << baddie.getDamage() << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	system("pause");
	system("cls");
	while (run)
	{
		std::cout << "==================================================" << std::endl;
		std::cout << "                      Battle:                     " << std::endl;
		std::cout << "==================================================" << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Health: " << getHealth() << std::endl;
		std::cout << "=====" << std::endl;
		std::cout << " VS" << std::endl;
		std::cout << "=====" << std::endl;
		std::cout << "Name: " << baddie.getName() << std::endl;
		std::cout << "Health: " << baddie.getHealth() << std::endl;
		std::cout << "==================================================" << std::endl;

		/*
		Used to determine who will go first.
		*/
		srand(time(0));

		int isPlayerFirst = rand() % 2;
		std::cout << isPlayerFirst << std::endl;

		isPlayerFirst = 1; //ALWAYS FIRST MAYBE CHANGE THIS LATER.

		if (isPlayerFirst == 1)
		{
			std::cout << "You will go first" << std::endl;
			std::cout << "==================================================" << std::endl;
			std::cout << "                      Choice:                     " << std::endl;
			std::cout << "==================================================" << std::endl;
			std::cout << "[1] Attack your opponent." << std::endl;
			std::cout << "[2] Block your opponent." << std::endl;
			int userChoice;
			std::cin >> userChoice;

			int dealtDamage = rand() % m_weapon.getDamage();
			bool isBlocked = false;
			switch (userChoice)
			{
			case 1:
				std::cout << "You have chosen to attack your opponent." << std::endl;

				std::cout << dealtDamage << std::endl;
				baddie.setHealth(baddie.getHealth() - dealtDamage);

				break;
			case 2:
				std::cout << "You have chosen to block your opponent." << std::endl;
				isBlocked = true;
				break;

			default:
				std::cout << "Invalid Choice" << std::endl;
				break;
			}

			if (baddie.getHealth() <= 0)
			{
				std::cout << "Baddie Health is Zero" << std::endl;
				return 1;
			}

			int recievedDamage = rand() % baddie.getDamage();
			std::cout << "Recieved Damage: " << recievedDamage << std::endl;
			if (isBlocked)
			{
				recievedDamage = recievedDamage * 0.5;
				std::cout << "Blocked Damage: " << recievedDamage << std::endl;

				dealtDamage = rand() % 4 + 1;
				std::cout << "Block Damage to the Enemy: " << dealtDamage << std::endl;

				baddie.setHealth(baddie.getHealth() - dealtDamage);
			}
			setHealth(getHealth() - recievedDamage);
		}
		else
		{
			std::cout << "You opponent will go first" << std::endl;
		}

		if (getHealth() <= 0)
		{
			std::cout << "Player Health is zero" << std::endl;

			return 0;
		}

		system("pause");
		system("cls");
	}
}