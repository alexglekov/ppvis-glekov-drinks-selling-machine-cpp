#pragma once

#include "../../base/drink_selling_machine/machine_elements/IngredientOperator.h"

class IngredientOperatorWithSpeed : public IngredientOperator
{
public:
	IngredientOperatorWithSpeed(const std::string& name, const Ingredients& ingredients);
    bool _operateIngredient() override;

private:
	const uint32_t m_speed = 2;
};
