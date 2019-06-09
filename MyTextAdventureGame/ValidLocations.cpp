#include <iostream>
#include <string>
#include <cstdlib>
#include "ValidLocations.h"
#include "ValidItems.h"
#include "Player.h"

//Location for all of the locations details and descriptions.
//Thought this would be neater and easier to use.
ValidLocations::ValidLocations(void)
{
	intro = "One day you wake up in the middle of a field hundreds of miles from civilisation. For no \
aparent reason. The field is surrounded by by tall dense trees. You notice a small brick shed \
in the center. Having no choice, You decide to investigate. You quickly realise it is nearly empty\
 except from a ladder going down into a dark abyss. You decide to investigate further and go down.";

	introContinued = "As you carefully decend down the ladder, the ground begins to shake and the ladder\
 suddenly breaks. You tumble to the floor. You now have no choice but to explore. You are armed only with\
a small knife. Your journey begins. ";

	A.setName("North - West Boss");
	A.setId("A");
	A.setDescription("A large empty room with only a fierce gnoblin.");
	A.setIsEnemyAlive(true);
	Enemy EnemyA;
	EnemyA.setName("Gnoblin");
	EnemyA.setPhrase("I'm gnot a Gnelf, I'm gnot a Gnelf, I'm a Gnome.");
	EnemyA.setKillPhrase("You've been Gnomed!");
	EnemyA.setDeathPhrase("I've been gnomed!");
	EnemyA.setDamage(20);
	EnemyA.setGold(25);
	EnemyA.setWeapon(validItems.gnoblinWeapon);
	A.setEnemy(EnemyA);

	B.setName("Room");
	B.setId("B");
	B.setDescription("Just a eerie room. You have two options. East or South.");
	B.setIsEnemyAlive(false);
	B.setItem(validItems.mediumHealth);
	B.setItemExist(true);

	C.setName("Room");
	C.setId("C");
	C.setDescription("At first, it looks just like any other room. But upon closer inspection, \
you notice that there is a mysterious vending machine, selling all sorts of magical items. \
You think to yourself, \"Maybe I can use it with these gold coins?\". \
You have two options. South or West");
	C.setIsEnemyAlive(false);

	D.setName("North - East Boss");
	D.setId("D");
	D.setDescription("You quietly creep into the room. But not quiet enough. You have one option. South.");
	D.setIsEnemyAlive(true);
	Enemy EnemyD;
	EnemyD.setName("Gnelf");
	EnemyD.setPhrase("I'm gnot a Gnome, I'm gnot a Gnoblin, I'm a Gnelf.");
	EnemyD.setKillPhrase("You've been Gnelfed!");
	EnemyD.setDeathPhrase("I've been Gnelfed!");
	EnemyD.setDamage(10);
	EnemyD.setGold(20);
	EnemyD.setWeapon(validItems.gnelfWeapon);
	D.setEnemy(EnemyD);
	

	E.setName("Corridor to a Boss");
	E.setId("E");
	E.setDescription("Corridor to the North - West Boss. You have two options. North (Boss) or South.");
	E.setIsEnemyAlive(false);

	F.setName("Starter Room");
	F.setId("F");
	F.setDescription("This is the first room you step foot in, after going down the ladder. \
You have two options. North or West.");
	F.setIsEnemyAlive(false);
	F.setItemExist(true);
	F.setItem(validItems.smallSword);

	G.setName("G Room Name");
	G.setId("G");
	G.setDescription("Just a eerie room. You have two options. North or East.");
	G.setIsEnemyAlive(false);

	H.setName("Corridor to the Gnelf Boss");
	H.setId("H");
	H.setDescription("Access to the North - East Boss. You have two options. North (Boss) or South.");
	H.setIsEnemyAlive(false);

	I.setName("I Room Name");
	I.setId("I");
	I.setDescription("Just a eerie room. You have three options. North, East or South.");
	I.setIsEnemyAlive(false);

	J.setName("J Room Name");
	J.setId("J");
	J.setDescription("Just a eerie room. You have two options. North or West.");
	J.setIsEnemyAlive(false);

	K.setName("K Room Name");
	K.setId("K");
	K.setDescription("Just a eerie room. You have two options. East or South.");
	K.setIsEnemyAlive(false);

	L.setName("L Room Name");
	L.setId("L");
	L.setDescription("Just a eerie room. You have two options. North or West.");
	L.setIsEnemyAlive(false);
	
	M.setName("South - West Boss ");
	M.setId("M");
	M.setDescription("The Gnoblin hears you. You're in trouble. You have two option. \
North or East. If you can survive...");
	M.setIsEnemyAlive(true);
	Enemy EnemyM;
	EnemyM.setName("Gnome");
	EnemyM.setPhrase("I'm gnot a Gnelf, I'm gnot a Gnome, I'm a Gnoblin.");
	EnemyM.setKillPhrase("You've been Gnoblined!");
	EnemyM.setDeathPhrase("I've been Gnoblined!");
	EnemyM.setDamage(15);
	EnemyM.setGold(15);
	EnemyM.setWeapon(validItems.gnomeWeapon);
	M.setEnemy(EnemyM);

	N.setName("N Room Name");
	N.setId("N");
	N.setDescription("Just a eerie room. You have two options. East or West.");
	N.setIsEnemyAlive(false);

	O.setName("O Room Name");
	O.setId("O");
	O.setDescription("Just a eerie room. You have three options. North, East or West.");
	O.setIsEnemyAlive(false);

	P.setName("South - East Boss");
	P.setId("P");
	P.setDescription("The Gnoblin hears you. You're in trouble. You have one option. West. \
If you can survive...");
	P.setIsEnemyAlive(true);
	Enemy EnemyP;
	EnemyP.setName("Gnome");
	EnemyP.setPhrase("I'm gnot a Gnelf, I'm gnot a Gnoblin, I'm a Gnoblin.");
	EnemyP.setKillPhrase("You've been Gnoblined!");
	EnemyP.setDeathPhrase("I've been Gnoblined!");
	EnemyP.setDamage(15);
	EnemyP.setGold(15);
	EnemyP.setWeapon(validItems.gnomeWeapon);
	P.setEnemy(EnemyP);
}

void ValidLocations::update(std::string map[7][7], Player player)
{
	if (map[player.getY()][player.getX()] == "A")
	{
		A = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "B")
	{
		B = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "C")
	{
		C = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "D")
	{
		D = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "E")
	{
		E = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "F")
	{
		F = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "G")
	{
		G = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "H")
	{
		H = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "I")
	{
		I = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "J")
	{
		J = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "K")
	{
		K = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "L")
	{
		L = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "M")
	{
		M = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "N")
	{
		N = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "O")
	{
		O = player.m_currentLocation;
	}
	else if (map[player.getY()][player.getX()] == "P")
	{
		P = player.m_currentLocation;
	}
}
