#pragma once

#include "IngredientStorage.h"
#include "../../config/Settings.h"

class IngredientOperator
{
public:
	using Ingredients = std::vector<std::string>;

	IngredientOperator(const std::string& name, const Ingredients& ingredients);
	bool operateIngredient();
	void passReceiptIngredient(const std::string& receipt, const std::string& ingredient);

	std::string name();

protected:

	virtual bool _operateIngredient();
	void cleanReceiptIngredientSlot();

protected:
	std::string m_name;

	const settings::ReceiptDesc::Ingredient* m_currentIngredient = nullptr;
	std::string  m_currentReceipt;

	Ingredients m_bindedIngredients;
};
