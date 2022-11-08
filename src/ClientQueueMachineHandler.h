#pragma once

#include <memory>

class Client;
class IOrderable;

class ClientQueueMachineHandler
{
public:
	ClientQueueMachineHandler();
	~ClientQueueMachineHandler();

	void run();

private:
	void createClient();

private:
	std::unique_ptr<IOrderable> m_machine;

	std::unique_ptr<Client> m_client;
	const uint32_t ClientGenerationDelta;
};
