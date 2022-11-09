#pragma once

#include "IngredientOperator.h"

class IngredientOperatorWithMistake : public IngredientOperator
{
public:
	IngredientOperatorWithMistake(const std::string& name, const Ingredients& ingredients);
	bool _operateIngredient() override;
};
