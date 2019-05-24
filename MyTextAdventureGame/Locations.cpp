#include <iostream>
#include <string>
#include <cstdlib>
#include "Locations.h"

//Location for all of the locations details and descriptions.
//Thought this would be neater and easier to use.
Locations::Locations(void)
{
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

	B.setName("B Room Name");
	B.setId("B");
	B.setDescription("B Room Description11");

	C.setName("C Room Name");
	C.setId("C");
	C.setDescription("C Room Description11");

	D.setName("North - East Boss");
	D.setId("D");
	D.setDescription("D Room Description11");

	E.setName("E Room Name");
	E.setId("E");
	E.setDescription("E Room Description11");

	F.setName("F Room Name");
	F.setId("F");
	F.setDescription("F Room Description11");

	G.setName("G Room Name");
	G.setId("G");
	G.setDescription("G Room Description11");

	H.setName("H Room Name");
	H.setId("H");
	H.setDescription("H Room Description11");

	I.setName("I Room Name");
	I.setId("I");
	I.setDescription("I Room Description11");

	J.setName("J Room Name");
	J.setId("J");
	J.setDescription("J Room Description11");

	K.setName("K Room Name");
	K.setId("K");
	K.setDescription("K Room Description11");

	L.setName("L Room Name");
	L.setId("L");
	L.setDescription("L Room Description11");

	M.setName("M Room Name");
	M.setId("M");
	M.setDescription("M Room Description11");

	N.setName("N Room Name");
	N.setId("N");
	N.setDescription("N Room Description11");

	O.setName("O Room Name");
	O.setId("O");
	O.setDescription("O Room Description11");

	P.setName("South - East Boss");
	P.setId("P");
	P.setDescription("P Room Description11");
}
