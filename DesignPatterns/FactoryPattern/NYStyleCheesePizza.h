#pragma once

#include "Pizza.h"

class NYStyleCheesePizza : public Pizza
{
public:

	NYStyleCheesePizza() {
		name = "NY Style Sauce and Cheese Pizza";
		dough = "Thin Crust Dough";
		sauce = "Mariana Sauce";

		toppings.push_back("Greated raggiano cheese");
	}
};