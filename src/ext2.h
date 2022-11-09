#pragma once

#include "Client.h"

class ClientWithPick : public Client
{
public:
	bool pickDrink(IOrderable* machine) override;

private:
	size_t m_pickCount = 0;
};
