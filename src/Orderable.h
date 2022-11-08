#pragma once

#include <vector>
#include <string>

class Item;

class IOrderable
{
public:
	virtual ~IOrderable();

	using Menu = std::vector<std::string>;
	virtual Menu getMenu() const = 0;

	virtual const Item* makeOrder(const std::string& drink) = 0;

	virtual bool isAvailable() const = 0;
	virtual bool isPositionAvailable(const std::string& drink) const = 0;
};
