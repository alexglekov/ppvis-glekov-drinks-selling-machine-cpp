#pragma once

#include "../abstract/Orderable.h"

#include "../config/Settings.h"
#include "../drink_selling_machine/machine_elements/PreReadyGoodsStorage.h"
#include "../drink_selling_machine/machine_elements/IngredientOperator.h"
#include "../drink_selling_machine/goods/Drinks.h"

#include <chrono>
#include <string>
#include <unordered_map>

template <typename OperatorType>
class DrinkSellingMachine : public IOrderable
{
public:
	DrinkSellingMachine()
	{
		for (const auto& desc : settings::Components)
			m_components[desc.name] = std::make_unique<OperatorType>(desc.name, desc.ingredients);

		m_storages["ingredient_storage"] = std::make_unique<IngredientStorage>("ingredient_storage");
		m_storages["pre_ready_goods"] = std::make_unique<PreReadyGoodsStorage>("pre_ready_goods");

		for (const auto& desc : settings::Receipts)
			m_receipts[desc.name] = &desc;

		m_timeStart = clock();
		m_workTimeDelta = settings::WorkDeltaTime;
	}

	const Item* makeOrder(const std::string& drink) override
	{
		return executeOrder(drink);
	}

	bool isAvailable() const override
	{
		return clock() < m_timeStart + m_workTimeDelta;
	}

	bool isPositionAvailable(const std::string& drink) const override
	{
		return checkOrderPossibility(drink);
	}

	Menu getMenu() override
	{
		const auto& preReadyGoods = m_storages.at("pre_ready_goods")->getCurrentState();

		Menu menu;
		menu.reserve(m_receipts.size() + preReadyGoods.size());

		for (const auto& receipt : m_receipts)
			menu.push_back(receipt.first);

		for (const auto& preReadyGood : preReadyGoods)
			menu.push_back(preReadyGood.first);

		return menu;
	}

private:
	const settings::ReceiptDesc* getReceipt(const std::string& drink)
	{
		return m_receipts[drink];
	}

	const Item* executeReceipt(const settings::ReceiptDesc* receipt, const std::string& drink)
	{
		const auto& requiredIngrs = receipt->ingredients;
		if (getRequiredIngredients(receipt))
		{
			for (const auto& ingr : receipt->ingredients)
			{
				const auto& reqComponent = ingr.component;
				m_components[reqComponent]->passReceiptIngredient(receipt->name, ingr.name);
			}

			if (!triggerOperations())
				return nullptr;

			return new CoockedDrink(drink);
		}

		return nullptr;
	}

	const Item* executeOrder(const std::string& drink)
	{
		if (!checkOrderPossibility(drink))
			return nullptr;

		auto itReceipt = m_receipts.find(drink);
		if (itReceipt != m_receipts.cend())
		{
			return executeReceipt(itReceipt->second, drink);
		}
		else
		{
			return getPreReadyGood(drink);
		}
	}

	bool checkOrderPossibility(const std::string& drink) const
	{
		auto preReadyStorage = static_cast<PreReadyGoodsStorage*>(m_storages.at("pre_ready_goods").get());
		auto preReadyItems = preReadyStorage->getCurrentState();
		auto itPreReady = preReadyItems.find(drink);

		if (itPreReady != preReadyItems.cend())
			return preReadyStorage->checkStoredItem(drink, 1);

		auto itReceipt = m_receipts.find(drink);
		if (itReceipt != m_receipts.cend())
		{
			auto storageState = m_storages.at("ingredient_storage")->getCurrentState();
			for (const auto& ingr : itReceipt->second->ingredients)
			{
				if (ingr.amount > storageState.at(ingr.name))
					return false;
			}

			return true;
		}

		return false;
	}

	const PreCoockedDrink* getPreReadyGood(const std::string& drink)
	{
		auto storage = static_cast<PreReadyGoodsStorage*>(m_storages["pre_ready_goods"].get());
		return storage->getElement(drink, 1);
	}

	bool getRequiredIngredients(const settings::ReceiptDesc* receipt)
	{
		auto ingrStorage = static_cast<IngredientStorage*>(m_storages["ingredient_storage"].get());
		return ingrStorage->getReceiptIngredients(receipt);
	}

	bool triggerOperations()
	{
		for (auto& component : m_components)
		{
			if (!component.second->operateIngredient())
				return false;
		}

		return true;
	}


private:
	std::unordered_map<std::string, std::unique_ptr<Storage>> m_storages;
	std::unordered_map<std::string, std::unique_ptr<IngredientOperator>> m_components;
	std::unordered_map<std::string, const settings::ReceiptDesc*> m_receipts;

	uint32_t m_timeStart;
	uint32_t m_workTimeDelta;

};
