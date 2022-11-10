#pragma once

#include "Item.h"

class Ingredient : public Item
{
public:
	Ingredient(const std::string& name, size_t amount);
	size_t m_amount;
};
