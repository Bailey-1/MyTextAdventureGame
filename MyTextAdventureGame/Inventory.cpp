#include "Inventory.h"
#include <iostream>
#include <string>

Item Inventory::getItems(void) { return *m_items; }
void Inventory::setItems(Item itemArray) { *m_items = itemArray; }

Item Inventory::getItem(int i) { return m_items[i]; }

int Inventory::getSize(void) { return m_size; }
void Inventory::setSize(int size) { m_size = size; }

void Inventory::pickupItem(Item item) 
{
	for (int i = 0; i <= m_size-1; i++)
	{
		if (m_items[i].getName() == "")
		{
			m_items[i] = item;
			return;
		}
	}
}
