#include "IngredientStorage.h"

#include "Ingredient.h"
#include "Settings.h"

IngredientStorage::IngredientStorage(const std::string& name)
	: Storage(name)
{
	for (const auto& desc : settings::Ingredients)
		m_items[desc.name] = std::make_unique<Ingredient>(desc.name, desc.amount);
}

bool IngredientStorage::getReceiptIngredients(const settings::ReceiptDesc* receipt)
{
	auto currentState = getCurrentState();

	const auto& requiredIngrs = receipt->ingredients;
	for (const auto ingr : requiredIngrs)
	{
		if (ingr.amount > currentState[ingr.name])
			return false;
	}

	for (auto& ingr : requiredIngrs)
	{
		auto storageIngredient = static_cast<Ingredient*>(m_items[ingr.name].get());
		storageIngredient->m_amount -= ingr.amount;
	}

	return true;
}

IngredientStorage::State IngredientStorage::getCurrentState() const
{
	State state;

	for (const auto& item : m_items)
		state[item.first] = static_cast<Ingredient*>(item.second.get())->m_amount;

	return state;
}
