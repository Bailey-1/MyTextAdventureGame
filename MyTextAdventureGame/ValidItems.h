#pragma once
#include <iostream>
#include <string>
#include "Item.h"

class ValidItems
{
protected:

public:
	ValidItems(void);
	Item smallKnife;

	Item smallSword;
	Item mediumSword;
	Item largeSword;

	Item smallHealth;
	Item mediumHealth;
	Item largeHealth;
};
