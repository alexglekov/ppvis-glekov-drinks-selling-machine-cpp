#pragma once

#include "IngredientStorage.h"
#include "Settings.h"

class IngredientOperator
{
public:
	using Ingredients = std::vector<std::string>;
	static std::unique_ptr<IngredientOperator> Create(const std::string& name, const Ingredients& ingredients);

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
