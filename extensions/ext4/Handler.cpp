#include "Handler.h"

void ClientQueueMachineHandlerWithStats::run()
{
	ClientQueueMachineHandler::run();
	static_cast<DrinkSellingMachineWithStats*>(m_machine.get())->printStatistics();
}
