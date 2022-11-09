#pragma once

#include "IngredientOperator.h"

class IngredientOperatorWithSpeed : public IngredientOperator
{
public:
	IngredientOperatorWithSpeed(const std::string& name, const Ingredients& ingredients);
    bool _operateIngredient() override;

private:
	const uint32_t m_speed = 1;
};
