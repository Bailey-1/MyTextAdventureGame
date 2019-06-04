#include <iostream>
#include <string>
#include <cstdlib>
#include "ValidItems.h"
#include "Player.h"

//Location for all items in the game;
//Thought this would be neater and easier to use.
ValidItems::ValidItems(void)
{
	smallKnife.setName("Small Pocket Knife");
	smallKnife.setType("Weapon");
	smallKnife.setDamage(15);
	smallKnife.setValue(50);
	smallKnife.setDescription("A small pocket knife, you happened to be carrying\
when you were transported here.");
	
	smallSword.setName("Small Sword");
	smallSword.setType("Weapon");
	smallSword.setDamage(20);
	smallSword.setValue(40);
	smallSword.setDescription("A small sword you found close to the enterance. It's probably worthless.");

	mediumSword.setName("Medium Sword");
	mediumSword.setType("Weapon");
	mediumSword.setDamage(30);
	mediumSword.setValue(80);
	mediumSword.setDescription("A standard medium sword you found on your travels.");

	largeSword.setName("Large Sword");
	largeSword.setType("Weapon");
	largeSword.setDamage(50);
	largeSword.setValue(150);
	largeSword.setDescription("A standard large sword you found on your travels.");

	smallHealth.setName("Small Health Potion +25");
	smallHealth.setDescription("A standard small health potion.");
	smallHealth.setType("Health");
	smallHealth.setHealth(25);
	smallHealth.setValue(25);

	mediumHealth.setName("Medium Health Potion +50");
	mediumHealth.setDescription("A standard medium health potion.");
	mediumHealth.setType("Health");
	mediumHealth.setHealth(50);
	smallHealth.setValue(50);

	largeHealth.setName("Large Health Potion +100");
	largeHealth.setDescription("A standard large health potion.");
	largeHealth.setType("Health");
	largeHealth.setHealth(100);
	smallHealth.setValue(100);

	gnoblinWeapon.setName("Gnoblin's Sword");
	gnoblinWeapon.setDescription("A standard sword that the Gnoblin likes.");
	gnoblinWeapon.setType("Weapon");
	gnoblinWeapon.setDamage(30);

	gnelfWeapon.setName("Gnelf Weapon");
	gnelfWeapon.setDescription("A standard sword that the Gnelf likes.");
	gnelfWeapon.setType("Weapon");
	gnelfWeapon.setDamage(15);

	gnomeWeapon.setName("Gnome Weapon");
	gnomeWeapon.setDescription("A standard sword that the Gnome likes.");
	gnomeWeapon.setType("Weapon");
	gnomeWeapon.setDamage(20);
}