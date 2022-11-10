#pragma once

#include "../../base/drink_selling_machine/DrinkSellingMachine.h"

#include <string>
#include <unordered_map>

class Item;

class DrinkSellingMachineWithStats : public DrinkSellingMachine<IngredientOperator>
{
public:
	Menu getMenu() override;
	const Item* makeOrder(const std::string& drink) override;

	void printStatistics();

private:
	std::unordered_map<std::string, size_t> m_drinkStats;
	size_t m_clientCounter = 0;
};
