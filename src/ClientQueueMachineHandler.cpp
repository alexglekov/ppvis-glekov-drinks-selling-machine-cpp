#include "ClientQueueMachineHandler.h"

#include "Client.h"
#include "DrinkSellingMachine.h"
#include "Settings.h"

#include <thread>

ClientQueueMachineHandler::ClientQueueMachineHandler()
	: ClientGenerationDelta(settings::ClientGenerationDelta)
	, m_machine(std::make_unique<DrinkSellingMachine>())
{
	srand(time(0));
}

ClientQueueMachineHandler::~ClientQueueMachineHandler() = default;

void ClientQueueMachineHandler::run()
{
	while (m_machine->isAvailable())
	{
		createClient();
		m_client->orderDrink(m_machine.get());
		std::this_thread::sleep_for(std::chrono::seconds(ClientGenerationDelta));
	}
}

void ClientQueueMachineHandler::createClient()
{
	m_client = std::make_unique<Client>();
}
