#include "ClientQueueMachineHandler.h"

int main()
{
	auto cqm = ClientQueueMachineHandler::Create();
	cqm->run();

	return 0;
}
