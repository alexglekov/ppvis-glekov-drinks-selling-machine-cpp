#include "Client.h"

#include "Item.h"
#include "Orderable.h"
#include "Settings.h"

#include <iostream>

#include "ext2.h"

std::unique_ptr<Client> Client::Create()
{
#if defined(EXT_2)
	return std::make_unique<ClientWithPick>();
#else
	return std::make_unique<Client>();
#endif
}

Client::Client()
	: PossibleWaitTime(settings::ClientPossibleWaitTime)
{
}

bool Client::orderDrink(IOrderable* machine)
{
	auto pick = pickDrink(machine);
	if (pick)
	{
		m_orderTime = clock();
		std::cout << "Order execution is starting, ordered drink is " << m_chosenDrink << std::endl;
		auto order = _orderDrink(machine);
		if (order)
		{
			if (clock() <= m_orderTime + PossibleWaitTime)
			{
				m_receivedDrink = order;
				std::cout << "Order executed successfully, received drink is "
						  << m_receivedDrink->name() << ", client is leaving\n\n";

				delete order;
				return true;
			}
			else
			{
				std::cout << "Order has been executed for too long, client left\n";
			}

			delete order;
		}
		else
		{
			std::cout << "Order execution failed, client is leaving\n";
		}
	}
	else
	{
		std::cout << "Drink chosen by client is unavailable, client is leaving\n";
	}

	std::cout << std::endl;

	return false;
}

const Item* Client::receivedDrink() const
{
	return m_receivedDrink;
}

bool Client::pickDrink(IOrderable* machine)
{
	std::cout << "Client is picking drink\n";

	const auto menu = machine->getMenu();
	m_chosenDrink = menu[rand() % menu.size()];
	// m_chosenDrink = "cappuccino";

	std::cout << "Chosen drink: " << m_chosenDrink << std::endl;

	if (machine->isPositionAvailable(m_chosenDrink))
	{
		std::cout << "Chosen drink is available, proceeding to the next step\n";
		return true;
	}

	std::cout << "Chosen drink is unavailable\n";
	return false;
}

const Item* Client::_orderDrink(IOrderable* machine)
{
	return machine->makeOrder(m_chosenDrink);
}
