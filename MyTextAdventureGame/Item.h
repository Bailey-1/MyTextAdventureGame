#pragma once
#include <iostream>
#include <string>

class Item
{
protected:
	std::string m_name;
	std::string m_type;
	std::string m_description;

	int m_value;

	int m_damage;
	int m_health;
	float m_xpBonus;

public:
	std::string getName(void);
	void setName(std::string);
	std::string getType(void);
	void setType(std::string);
	std::string getDescription(void);
	void setDescription(std::string);

	void stats(void);

	int getValue(void);
	void setValue(int);

	int getDamage(void);
	void setDamage(int);
	int getHealth(void);
	void setHealth(int);
	float getXpBonus(void);
	void setXpBonus(float);
};

