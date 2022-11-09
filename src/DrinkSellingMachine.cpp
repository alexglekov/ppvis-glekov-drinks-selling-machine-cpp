#include "DrinkSellingMachine.h"

#include "Settings.h"
#include "IngredientOperator.h"
#include "PreReadyGoodsStorage.h"
#include "Drinks.h"

#include "ext4.h"

std::unique_ptr<DrinkSellingMachine> DrinkSellingMachine::Create()
{
#if defined(EXT_4)
	return std::make_unique<DrinkSellingMachineWithStats>();
#else
	return std::make_unique<DrinkSellingMachine>();
#endif
}

DrinkSellingMachine::DrinkSellingMachine()
{
	for (const auto& desc : settings::Components)
		m_components[desc.name] = IngredientOperator::Create(desc.name, desc.ingredients);

	m_storages["ingredient_storage"] = std::make_unique<IngredientStorage>("ingredient_storage");
	m_storages["pre_ready_goods"] = std::make_unique<PreReadyGoodsStorage>("pre_ready_goods");

	for (const auto& desc : settings::Receipts)
		m_receipts[desc.name] = &desc;

	m_timeStart = clock();
	m_workTimeDelta = settings::WorkDeltaTime;
}

DrinkSellingMachine::~DrinkSellingMachine()
{
}

bool DrinkSellingMachine::isAvailable() const
{
	return clock() < m_timeStart + m_workTimeDelta;
}

DrinkSellingMachine::Menu DrinkSellingMachine::getMenu()
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

const Item* DrinkSellingMachine::makeOrder(const std::string& drink)
{
	return executeOrder(drink);
}

bool DrinkSellingMachine::isPositionAvailable(const std::string& drink) const
{
	return checkOrderPossibility(drink);
}

const settings::ReceiptDesc* DrinkSellingMachine::getReceipt(const std::string& drink)
{
	return m_receipts[drink];
}

const Item* DrinkSellingMachine::executeReceipt(const settings::ReceiptDesc* receipt, const std::string& drink)
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

bool DrinkSellingMachine::getRequiredIngredients(const settings::ReceiptDesc* receipt)
{
	auto ingrStorage = static_cast<IngredientStorage*>(m_storages["ingredient_storage"].get());
	return ingrStorage->getReceiptIngredients(receipt);
}

const Item* DrinkSellingMachine::executeOrder(const std::string& drink)
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

bool DrinkSellingMachine::checkOrderPossibility(const std::string& drink) const
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

const PreCoockedDrink* DrinkSellingMachine::getPreReadyGood(const std::string& drink)
{
	auto storage = static_cast<PreReadyGoodsStorage*>(m_storages["pre_ready_goods"].get());
	return storage->getElement(drink, 1);
}

bool DrinkSellingMachine::triggerOperations()
{
	for (auto& component : m_components)
	{
		if (!component.second->operateIngredient())
			return false;
	}

	return true;
}
