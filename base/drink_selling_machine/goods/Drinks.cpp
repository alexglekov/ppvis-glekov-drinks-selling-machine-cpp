#include "Drinks.h"

PreCoockedDrink::PreCoockedDrink(const std::string& name, size_t amount)
	: Item(name)
	, m_amount(amount)
{
}

std::string PreCoockedDrink::repr() const
{
	return std::string("Pre ready good: ") + m_name;
}


CoockedDrink::CoockedDrink(const std::string& name)
	: Item(name)
{
}

std::string CoockedDrink::repr()
{
	return std::string("Coocked drink: " + m_name);
}
