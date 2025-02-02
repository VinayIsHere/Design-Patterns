#pragma once

#include "Pizza.h"

class ChicagoStylePepporoniPizza : public Pizza
{
public:

	ChicagoStylePepporoniPizza() {
		name = "ChicagoStylePepporoniPizza";
		dough = "ChicagoStylePepporoniPizza dough";
		sauce = "ChicagoStylePepporoniPizza sauce";
		toppings.push_back("ChicagoStylePepporoniPizza toppings");
	}

	void cut() override {
		std::cout << "ChicagoStylePepporoniPizza cutting pizza" << std::endl;
	}
};