#pragma once

#include "Storage.h"
#include "../../config/Settings.h"

#include <vector>
#include <string>

class IngredientStorage : public Storage
{
public:
	IngredientStorage(const std::string& name);

	struct IngredientConfig
	{
		std::string component;
		size_t amount;
		uint32_t time;
	};

	using Ingredients = std::vector<std::string>;
	bool getReceiptIngredients(const settings::ReceiptDesc* receipt);

	State getCurrentState() const override;
};
