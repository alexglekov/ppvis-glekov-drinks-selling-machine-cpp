#pragma once

#include "../../base/ClientQueueMachineHandler.h"
#include "DrinkSellingMachine.h"

class ClientQueueMachineHandlerWithStats : public ClientQueueMachineHandler<Client, DrinkSellingMachineWithStats>
{
public:
	void run() override;
};
