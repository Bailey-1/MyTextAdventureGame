#pragma once
#include <iostream>
#include <string>

class Tile
{
protected:
	std::string m_id;
	std::string m_name;
	std::string m_description;

public:
	std::string getId(void);
	void setId(std::string name);
	std::string getName(void);
	void setName(std::string name);
	std::string getDescription(void);
	void setDescription(std::string m_Name);
};

