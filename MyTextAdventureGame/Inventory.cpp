#include "Inventory.h"
#include <iostream>
#include <string>

Item Inventory::getItems(void) { return *m_items; }
void Inventory::setItems(Item itemArray) { *m_items = itemArray; }

int Inventory::getSize(void) { return m_size; }
void Inventory::setSize(int size) { m_size = size; }