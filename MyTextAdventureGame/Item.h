#pragma once
#include <iostream>
#include <string>

class Item
{
protected:
	std::string m_name;
	std::string m_type;
	std::string m_description;

	int m_damage;
	
public:
	std::string getName(void);
	void setName(std::string);
	std::string getType(void);
	void setType(std::string);
	std::string getDescription(void);
	void setDescription(std::string);

	int getDamage(void);
	void setDamage(int);
};

