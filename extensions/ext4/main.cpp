#include "../../base/ClientQueueMachineHandler.h"
#include "Handler.h"

int main()
{
	ClientQueueMachineHandlerWithStats cqm;
	cqm.run();

	return 0;
}
