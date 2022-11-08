#include "Storage.h"

Storage::Storage(const std::string& name)
	: m_name(name)
{
}

bool Storage::checkStoredItem(const std::string& name, size_t amount) const
{
	return true;
}

Storage::State Storage::getCurrentState() const
{
	return {};
}
