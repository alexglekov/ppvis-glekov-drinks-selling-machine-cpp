#include "Client.h"

#include "../../base/abstract/Orderable.h"

#include <iostream>

bool ClientWithPick::pickDrink(IOrderable* machine)
{
	const auto menu = machine->getMenu();
	while (m_pickCount < 2)
	{
		std::cout << "Client is picking drink: try #" << m_pickCount + 1 << std::endl;
		m_chosenDrink = m_chosenDrink = menu[rand() % menu.size()];
		std::cout << "Chosen drink: " << m_chosenDrink << std::endl;
		if (machine->isPositionAvailable(m_chosenDrink))
		{
			std::cout << "Chosen drink is available, proceeding to the next step\n";
			return true;
		}
		else
		{
			std::cout << "Chosen drink is unavailable\n";
			m_pickCount++;
		}
	}

	std::cout << "Client's amount of picks is over\n";
	return false;
}
