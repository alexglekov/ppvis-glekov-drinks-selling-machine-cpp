#pragma once

#include <string>

class Item
{
public:
	Item(const std::string& name);
	virtual ~Item();

	std::string name() const;

protected:
	std::string m_name;
};
