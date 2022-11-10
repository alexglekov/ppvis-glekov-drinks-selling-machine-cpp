#pragma once

#include <string>
#include <vector>

namespace settings
{
	struct CommonItemDesc
	{
		std::string name;
		size_t amount;
	};

	struct ComponentDesc
	{
		std::string name;
		std::vector<std::string> ingredients;
	};

	struct ReceiptDesc
	{
		struct Ingredient
		{
			std::string name;
			std::string component;
			uint32_t time;
			size_t amount;
		};

		std::string name;
		std::vector<Ingredient> ingredients;
	};

	const CommonItemDesc Ingredients[] = {
		{ "milk", 600 },
		{ "coffee_beans", 100 },
		{ "syrup", 200 }
	};

	const CommonItemDesc PreReadyGoods[] =	{
		{ "cola", 10 },
		{ "fanta", 10 },
		{ "sprite", 10 }
	};

	const ComponentDesc Components[] = {
		{ "cappuccinator", { "milk" } },
		{ "bean_grinder", { "coffee_beans" } },
		{ "dozator", { "syrup" } },
		{ "boiler", { "milk" } },
	};

	const ReceiptDesc Receipts[] = {
		{ "cappuccino", {
			 	{ "milk", "cappuccinator", 5, 150 },
				{ "coffee_beans", "bean_grinder", 5, 10 },
				{ "syrup", "dozator", 1, 50 } }},
		{ "latte", {
				{ "milk", "boiler", 5, 250 },
				{ "coffee_beans", "bean_grinder", 3, 5 },
				{ "syrup", "dozator", 1, 50 } }},
		{ "espresso", {
				{ "coffee_beans", "bean_grinder", 3, 20 } }}
	};

	constexpr uint32_t WorkDeltaTime = 20 * CLK_TCK;
	constexpr uint32_t ClientPossibleWaitTime = 30 * CLK_TCK;

	constexpr uint32_t ClientGenerationDelta = 5;


}
