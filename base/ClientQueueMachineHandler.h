#pragma once

#include <memory>

#include "client/Client.h"
#include "drink_selling_machine/DrinkSellingMachine.h"
#include "config/Settings.h"

#include <thread>

template <typename ClientType = Client, typename MachineType = DrinkSellingMachine<IngredientOperator>>
class ClientQueueMachineHandler
{
public:
	ClientQueueMachineHandler()
		: ClientGenerationDelta(settings::ClientGenerationDelta)
		, m_machine(std::make_unique<MachineType>())
	{
		srand(time(0));
	}

	~ClientQueueMachineHandler() = default;

	virtual void run()
	{
		while (m_machine->isAvailable())
		{
			createClient();
			m_client->orderDrink(m_machine.get());
			std::this_thread::sleep_for(std::chrono::seconds(ClientGenerationDelta));
		}
	}

private:
	void createClient()
	{
		m_client = std::make_unique<ClientType>();
	}

protected:
	std::unique_ptr<IOrderable> m_machine;

	std::unique_ptr<Client> m_client;
	const uint32_t ClientGenerationDelta;
};
