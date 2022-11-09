#pragma once

#include "ClientQueueMachineHandler.h"
#include "DrinkSellingMachine.h"

#include <string>
#include <unordered_map>

class Item;

class DrinkSellingMachineWithStats : public DrinkSellingMachine
{
public:
	Menu getMenu() override;
	const Item* makeOrder(const std::string& drink) override;

	void printStatistics();

private:
	std::unordered_map<std::string, size_t> m_drinkStats;
	size_t m_clientCounter = 0;
};

class ClientQueueMachineHandlerWithStats : public ClientQueueMachineHandler
{
public:
	void run() override;
};
