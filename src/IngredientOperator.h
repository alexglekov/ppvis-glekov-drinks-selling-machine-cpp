#pragma once

#include "IngredientStorage.h"
#include "Settings.h"

class IngredientOperator
{
public:
	using Ingredients = std::vector<std::string>;
	IngredientOperator(const std::string& name, const Ingredients& ingredients);
	void operateIngredient();
	void passReceiptIngredient(const std::string& receipt, const std::string& ingredient);

	std::string name();

private:
	void _operateIngredient();
	void cleanReceiptIngredientSlot();

private:
	std::string m_name;

	const settings::ReceiptDesc::Ingredient* m_currentIngredient = nullptr;
	std::string  m_currentReceipt;

	Ingredients m_bindedIngredients;
};
