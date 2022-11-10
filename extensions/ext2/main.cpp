#include "../../base/ClientQueueMachineHandler.h"
#include "Client.h"

int main()
{
	ClientQueueMachineHandler<ClientWithPick> cqm;
	cqm.run();

	return 0;
}
