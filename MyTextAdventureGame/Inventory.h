#pragma once
#include <iostream>
#include <string>
#include "Item.h"

class Inventory
{
protected:
	Item m_items[50];
	int m_size;

public:
	Item getItems(void); //Get array of items
	void setItems(Item); //Set array of items

	Item getItem(int); //Get item from array location
	void removeItem(int);

	bool pickupItem(Item); //Add single item to inventory in next location

	void swapItem(int, int);
	void viewInventory(void);

	int getSize(void); //Get max size of inventory
	void setSize(int); //Set max size of inventory
};
