#pragma once

#include "Drinks.h"
#include "Storage.h"

class PreReadyGoodsStorage : public Storage
{
public:
	PreReadyGoodsStorage(const std::string& name);
	PreCoockedDrink* getElement(const std::string& name, size_t amount);

	bool checkStoredItem(const std::string& name, size_t amount) const override;
	State getCurrentState() const override;
};
