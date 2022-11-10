#include "IngredientOperator.h"

#include <iostream>
#include <thread>

IngredientOperator::IngredientOperator(const std::string& name, const std::vector<std::string>& ingredients)
	: m_name(name)
	, m_bindedIngredients(ingredients)
{
}

bool IngredientOperator::operateIngredient()
{
	const auto res = _operateIngredient();
	cleanReceiptIngredientSlot();

	return res;
}

void IngredientOperator::passReceiptIngredient(const std::string& receipt, const std::string& ingredient)
{
	for (const auto& r : settings::Receipts)
	{
		if (r.name != receipt)
			continue;

		for (const auto& ingr : r.ingredients)
		{
			if (ingr.name == ingredient)
			{
				m_currentIngredient = &ingr;
				break;
			}
		}
	}
}

std::string IngredientOperator::name()
{
	return m_name;
}

bool IngredientOperator::_operateIngredient()
{
    if (m_currentIngredient == nullptr)
        return true;

    std::cout << m_name << ": required operation time = " << m_currentIngredient->time << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(m_currentIngredient->time));

	return true;
}

void IngredientOperator::cleanReceiptIngredientSlot()
{
	m_currentIngredient = nullptr;
}
