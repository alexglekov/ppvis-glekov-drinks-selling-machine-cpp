#pragma once

#include "../../base/drink_selling_machine/machine_elements/IngredientOperator.h"

class IngredientOperatorWithMistake : public IngredientOperator
{
public:
	IngredientOperatorWithMistake(const std::string& name, const Ingredients& ingredients);
	bool _operateIngredient() override;
};
