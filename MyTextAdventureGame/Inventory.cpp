#include "Inventory.h"
#include <iostream>
#include <string>

Item Inventory::getItems(void) { return *m_items; }
void Inventory::setItems(Item itemArray) { *m_items = itemArray; }

Item Inventory::getItem(int i) { return m_items[i]; }
void Inventory::removeItem(int i) { m_items[i] = Item(); }

int Inventory::getSize(void) { return m_size; }
void Inventory::setSize(int size) { m_size = size; }

bool Inventory::pickupItem(Item item) 
{
	for (int i = 0; i <= m_size-1; i++)
	{
		if (m_items[i].getName() == "")
		{
			m_items[i] = item;
			return true;
		}
	}
	return false;
}

void Inventory::swapItem(int a, int b)
{
	Item c = m_items[b];
	m_items[b] = m_items[a];
	m_items[a] = c;
}

void Inventory::viewInventory(void)
{
	for (int i = 0; i <= m_size - 1; i++)
	{
		std::cout << "[" << i + 1 << "] " << m_items[i].getName() << std::endl;
	}
}
