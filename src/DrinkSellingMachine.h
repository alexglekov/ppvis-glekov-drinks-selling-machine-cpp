#pragma once

#include "Orderable.h"

#include "IngredientStorage.h"

#include <chrono>
#include <string>
#include <unordered_map>

namespace settings
{
	struct ReceiptDesc;
}

class Storage;
class IngredientOperator;
class Item;
class PreReadyGoodsStorage;
class PreCoockedDrink;

class DrinkSellingMachine : public IOrderable
{
public:
	static std::unique_ptr<DrinkSellingMachine> Create();

	DrinkSellingMachine();
	~DrinkSellingMachine() override;

	const Item* makeOrder(const std::string& drink) override;

	bool isAvailable() const override;
	bool isPositionAvailable(const std::string& drink) const override;

	Menu getMenu() override;

private:
	const settings::ReceiptDesc* getReceipt(const std::string& drink);
	const Item* executeReceipt(const settings::ReceiptDesc* receipt, const std::string& drink);
	const Item* executeOrder(const std::string& drink);
	bool checkOrderPossibility(const std::string& drink) const;
	const PreCoockedDrink* getPreReadyGood(const std::string& drink);

	bool getRequiredIngredients(const settings::ReceiptDesc* receipt);
	bool triggerOperations();


private:
	std::unordered_map<std::string, std::unique_ptr<Storage>> m_storages;
	std::unordered_map<std::string, std::unique_ptr<IngredientOperator>> m_components;
	std::unordered_map<std::string, const settings::ReceiptDesc*> m_receipts;

	uint32_t m_timeStart;
	uint32_t m_workTimeDelta;

};
