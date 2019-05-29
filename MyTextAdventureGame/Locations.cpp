#include <iostream>
#include <string>
#include <cstdlib>
#include "Locations.h"

//Location for all of the locations details and descriptions.
//Thought this would be neater and easier to use.
Locations::Locations(void)
{
	intro = "Suddenly, you wake up in the middle of a field. Surrounded by trees. You notice a small brick shed in the center. Having no choice, You decide to investigate. You quickly realise it is empty apart from a ladder going down into a dark hole. You decide to investigate further and go down.";

	A.setName("North - West Boss");
	A.setId("A");
	A.setDescription("A large empty room with only a fierce gnoblin.");
	A.setIsEnemyAlive(true);
	Enemy EnemyA;
	EnemyA.setName("Gnoblin");
	EnemyA.setPhrase("I'm gnot a Gnelf, I'm gnot a Gnoblin, I'm a Gnome.");
	EnemyA.setKillPhrase("You've been Gnomed!");
	EnemyA.setDeathPhrase("I've been gnomed!");
	EnemyA.setDamage(20);
	EnemyA.setGold(25);
	A.setEnemy(EnemyA);

	B.setName("Room");
	B.setId("B");
	B.setDescription("Just a eerie room. You have two options. East or South.");

	C.setName("Room");
	C.setId("C");
	C.setDescription("At first, it looks just like any other room. But upon closer inspection, you notice that there is a mysterious vending machine, selling all sorts of magical items. You think to yourself, \"Maybe I can use it with these gold coins?\". You have two options. South or West");

	D.setName("North - East Boss");
	D.setId("D");
	D.setDescription("You quietly creep into the room. But not quiet enough. You have one option. South.");
	Enemy EnemyD;
	EnemyD.setName("Gnelf");
	EnemyD.setPhrase("I'm gnot a Gnome, I'm gnot a Gnoblin, I'm a Gnelf.");
	EnemyD.setKillPhrase("You've been Gnelfed!");
	EnemyD.setDeathPhrase("I've been Gnelfed!");
	EnemyD.setDamage(10);
	EnemyD.setGold(20);
	A.setEnemy(EnemyD);

	E.setName("Corridor to the Final Boss");
	E.setId("E");
	E.setDescription("Corridor to the North - West Boss. You have two options. North (Boss) or South.");

	F.setName("Starter Room");
	F.setId("F");
	F.setDescription("This is the first room you step foot in, after going down the ladder. You have two options. North or West.");

	G.setName("G Room Name");
	G.setId("G");
	G.setDescription("Just a eerie room. You have two options. North or East.");

	H.setName("Corridor to the Gnelf Boss");
	H.setId("H");
	H.setDescription("Access to the North - East Boss. You have two options. North (Boss) or South.");

	I.setName("I Room Name");
	I.setId("I");
	I.setDescription("Just a eerie room. You have three options. North, East or South.");

	J.setName("J Room Name");
	J.setId("J");
	J.setDescription("Just a eerie room. You have two options. North or West.");

	K.setName("K Room Name");
	K.setId("K");
	K.setDescription("Just a eerie room. You have two options. East or South.");

	L.setName("L Room Name");
	L.setId("L");
	L.setDescription("Just a eerie room. You have two options. North or West.");

	M.setName("South - West Boss ");
	M.setId("M");
	M.setDescription("The Gnoblin hears you. You're in trouble. You have two option. North or East. If you can survive...");
	Enemy EnemyM;
	EnemyM.setName("Gnoblin");
	EnemyM.setPhrase("I'm gnot a Gnelf, I'm gnot a Gnoblin, I'm a Gnoblin.");
	EnemyM.setKillPhrase("You've been Gnoblined!");
	EnemyM.setDeathPhrase("I've been Gnoblined!");
	EnemyM.setDamage(15);
	EnemyM.setGold(15);
	A.setEnemy(EnemyM);

	N.setName("N Room Name");
	N.setId("N");
	N.setDescription("Just a eerie room. You have two options. East or West.");

	O.setName("O Room Name");
	O.setId("O");
	O.setDescription("Just a eerie room. You have three options. North, East or West.");

	P.setName("South - East Boss");
	P.setId("P");
	P.setDescription("The Gnoblin hears you. You're in trouble. You have one option. West. If you can survive...");
	Enemy EnemyP;
	EnemyP.setName("Gnoblin");
	EnemyP.setPhrase("I'm gnot a Gnelf, I'm gnot a Gnoblin, I'm a Gnoblin.");
	EnemyP.setKillPhrase("You've been Gnoblined!");
	EnemyP.setDeathPhrase("I've been Gnoblined!");
	EnemyP.setDamage(15);
	EnemyP.setGold(15);
	A.setEnemy(EnemyP);
}
