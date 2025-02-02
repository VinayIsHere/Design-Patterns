#pragma once

#include "Pizza.h"

class NYStlePepporoniPizza : public Pizza
{
public:

	NYStlePepporoniPizza() {
		name = "NYStylePepporoniPizza";
		dough = "NYStylePepporoniPizza dough";
		sauce = "NYStylePepporoniPizza sauce";
		toppings.push_back("NYStylePepporoniPizza toppings");
	}

	void cut() override {
		std::cout << "NYStylePepporoniPizza cutting pizza";
	}
};