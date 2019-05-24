#pragma once
#include <iostream>
#include <string>
#include "Item.h"

class Inventory
{
protected:
	Item m_items[5];
	int m_size;

public:
	Item getItems(void);
	void setItems(Item);

	int getSize(void);
	void setSize(int);
};

