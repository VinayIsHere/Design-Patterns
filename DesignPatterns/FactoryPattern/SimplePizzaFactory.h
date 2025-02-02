#pragma once

#include <iostream>
#include <memory>
#include "Pizza.h"
#include "CheesePizza.h"
#include "PepporoniPizza.h"
#include "ClamPizza.h"
#include "VeggiePizza.h"

class SimplePizzaFactory
{
public:

	static std::shared_ptr<Pizza> createPizza(ePizzaType type) {
		
		if (type == ePizzaType::eCheese)
			return std::make_shared<CheesePizza>();
		else if (type == ePizzaType::ePepporoni)
			return std::make_shared<PepporoniPizza>();
		else if (type == ePizzaType::eClam)
			return std::make_shared<ClamPizza>();
		else if (type == ePizzaType::eVeggie)
			return std::make_shared<VeggiePizza>();
		else {
			std::cout << "wrong pizza type";
		}
	}
};