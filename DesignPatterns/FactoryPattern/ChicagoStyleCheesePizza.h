#pragma once

#include "Pizza.h"

class ChicagoStyleCheesePizza : public Pizza
{
public:

	ChicagoStyleCheesePizza() {
		name = "Chicago style deep dish cheese pizza";
		dough = "Extra thick crust dough";
		sauce = "Plut tomato sauce";
		toppings.push_back("Shredded Mozarella Cheese");
	}

	void cut() override {
		std::cout << "Cutting the pizza into square slices" << std::endl;
	}
};