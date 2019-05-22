#pragma once
#include <iostream>
#include <string>

class Inventory
{
protected:
	std::string items[5];
	int m_size;
	std::string m_name;

public:
	std::string getName(void);
	void setName(std::string);
	int getSize(void);
	void setSize(int);
	
	std::string getItems(void);
	void setItems(std::string[]);
};

