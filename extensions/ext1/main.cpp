#include "../../base/ClientQueueMachineHandler.h"
#include "IngredientOperator.h"

int main()
{
	ClientQueueMachineHandler<Client, DrinkSellingMachine<IngredientOperatorWithSpeed>> cqm;
	cqm.run();

	return 0;
}
