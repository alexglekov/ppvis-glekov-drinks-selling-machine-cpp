#include "PreReadyGoodsStorage.h"

#include "Settings.h"

PreReadyGoodsStorage::PreReadyGoodsStorage(const std::string& name)
	: Storage(name)
{
	for (const auto& desc : settings::PreReadyGoods)
		m_items[desc.name] = std::make_unique<PreCoockedDrink>(desc.name, desc.amount);
}

PreCoockedDrink* PreReadyGoodsStorage::getElement(const std::string& name, size_t amount)
{
	// Replace to find
	auto drink = static_cast<PreCoockedDrink*>(m_items[name].get());
	assert(drink != nullptr);

	if (drink->m_amount < amount)
		return nullptr;

	drink->m_amount -= amount;
	return new PreCoockedDrink(*drink);
}

bool PreReadyGoodsStorage::checkStoredItem(const std::string& name, size_t amount) const
{
	return static_cast<PreCoockedDrink*>(m_items.at(name).get())->m_amount >= amount;
}

PreReadyGoodsStorage::State PreReadyGoodsStorage::getCurrentState() const
{
	State state;

	for (const auto& item : m_items)
		state[item.first] = static_cast<PreCoockedDrink*>(item.second.get())->m_amount;

	return state;
}
