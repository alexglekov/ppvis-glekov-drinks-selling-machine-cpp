#pragma once

#include "Item.h"

#include <unordered_map>

class Storage
{
public:
	Storage(const std::string& name);
	virtual bool checkStoredItem(const std::string& name, size_t amount) const;

	using State = std::unordered_map<std::string, size_t>;
	virtual State getCurrentState() const;

private:
	std::string m_name;

protected:
	using Items = std::unordered_map<std::string, std::unique_ptr<Item>>;
	Items m_items;
};
