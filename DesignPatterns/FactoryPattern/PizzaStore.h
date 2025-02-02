#pragma once

#include <memory>
#include "Pizza.h"

class PizzaStore
{
public:
	
	PizzaStore() = default;

	std::shared_ptr<Pizza> orderPizza(ePizzaType type) {
		
		std::shared_ptr<Pizza> pizza = createPizza(type);
		pizza.get()->prepare();
		pizza.get()->bake();
		pizza.get()->cut();
		pizza.get()->box();
		
		return pizza;
	}

protected:

	virtual std::shared_ptr<Pizza> createPizza(ePizzaType type)= 0;
};