#include "Ingredient.h"

Ingredient::Ingredient(const std::string& name, size_t amount)
	: Item(name)
	, m_amount(amount)
{
}
