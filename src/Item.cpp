#include "Item.h"

Item::Item(const std::string& name)
	: m_name(name)
{
}

Item::~Item()
{
}

std::string Item::name() const
{
	return m_name;
}
