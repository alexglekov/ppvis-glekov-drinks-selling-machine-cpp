#include "ext4.h"

#include <iostream>

DrinkSellingMachineWithStats::Menu DrinkSellingMachineWithStats::getMenu()
{
	m_clientCounter++;
	return DrinkSellingMachine::getMenu();
}

const Item* DrinkSellingMachineWithStats::makeOrder(const std::string& drink)
{
	m_drinkStats[drink]++;
	return DrinkSellingMachine::makeOrder(drink);
}

void DrinkSellingMachineWithStats::printStatistics()
{
	std::cout << "Sold stats\n";
	for (const auto& d : m_drinkStats)
		std::cout << "Drink name: " << d.first << " amount of sold positions: " << d.second << std::endl;

	std::cout << "Amount of clients: " << m_clientCounter << std::endl;
}

void ClientQueueMachineHandlerWithStats::run()
{
	ClientQueueMachineHandler::run();
	static_cast<DrinkSellingMachineWithStats*>(m_machine.get())->printStatistics();
}
