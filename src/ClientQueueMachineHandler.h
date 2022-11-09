#pragma once

#include <memory>

class Client;
class IOrderable;

class ClientQueueMachineHandler
{
public:
	static std::unique_ptr<ClientQueueMachineHandler> Create();

	ClientQueueMachineHandler();
	~ClientQueueMachineHandler();

	virtual void run();

private:
	void createClient();

protected:
	std::unique_ptr<IOrderable> m_machine;

	std::unique_ptr<Client> m_client;
	const uint32_t ClientGenerationDelta;
};
