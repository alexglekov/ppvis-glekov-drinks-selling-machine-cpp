#include "IngredientOperator.h"

#include <iostream>
#include <thread>

IngredientOperatorWithSpeed::IngredientOperatorWithSpeed(const std::string& name, const Ingredients& ingredients)
	: IngredientOperator(name, ingredients)
{
}

bool IngredientOperatorWithSpeed::_operateIngredient()
{
	if (m_currentIngredient == nullptr)
        return true;

	const auto requiredTime = m_currentIngredient->time / m_speed;
    std::cout << m_name << ": required operation time = " << requiredTime << std::endl;

	assert(m_currentIngredient != nullptr);
	std::this_thread::sleep_for(std::chrono::seconds(requiredTime));

	return true;
}
