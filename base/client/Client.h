#pragma once

#include <cstdint>
#include <string>

class Item;
class IOrderable;

class Client
{
public:
	Client();
	bool orderDrink(IOrderable* machine);

	const Item* receivedDrink() const;

protected:
	virtual bool pickDrink(IOrderable* machine);
	const Item* _orderDrink(IOrderable* machine);

protected:
	std::string m_chosenDrink;
	const Item* m_receivedDrink;
	uint32_t m_orderTime = 0;

	const uint32_t PossibleWaitTime;
};
