#include "ext3.h"

#include <iostream>
#include <thread>

IngredientOperatorWithMistake::IngredientOperatorWithMistake(const std::string& name, const Ingredients& ingredients)
	: IngredientOperator(name, ingredients)
{
}

bool IngredientOperatorWithMistake::_operateIngredient()
{
	if (m_currentIngredient == nullptr)
		return true;

	std::this_thread::sleep_for(std::chrono::seconds(m_currentIngredient->time));
	if (!(rand() % 5)) // 20% mistake
	{
		std::cout << "Component " << m_name << " crashed, retrying\n";
		return false;
	}
	else
	{
		std::cout << "Component " << m_name << " worked properly, proceeding to the next step\n";
	}

	return true;
}
