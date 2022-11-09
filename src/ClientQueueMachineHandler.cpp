#include "ClientQueueMachineHandler.h"

#include "Client.h"
#include "DrinkSellingMachine.h"
#include "Settings.h"

#include <thread>

#include "ext4.h"

std::unique_ptr<ClientQueueMachineHandler> ClientQueueMachineHandler::Create()
{
#if defined(EXT_4)
	return std::make_unique<ClientQueueMachineHandlerWithStats>();
#else
		return std::make_unique<ClientQueueMachineHandler>();
#endif
}

ClientQueueMachineHandler::ClientQueueMachineHandler()
	: ClientGenerationDelta(settings::ClientGenerationDelta)
	, m_machine(DrinkSellingMachine::Create())
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
	m_client = Client::Create();
}
