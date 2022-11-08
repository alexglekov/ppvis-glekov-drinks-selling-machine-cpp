#pragma once

#include "Item.h"

class PreCoockedDrink : public Item
{
public:
	PreCoockedDrink(const std::string& name, size_t amount = -1);
	std::string repr() const;
	size_t m_amount;
};

class CoockedDrink : public Item
{
public:
	CoockedDrink(const std::string& name);
	std::string repr();
};
