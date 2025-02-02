#pragma once

#include "PizzaStore.h"
#include "CheesePizza.h"
#include "ClamPizza.h"
#include "ChicagoPizzaIngredientFactory.h"
#include "PizzaIngredientFactory.h"

class ChicagoPizzaStore : public PizzaStore
{
public:

	std::shared_ptr<Pizza> createPizza(ePizzaType type) override {

		std::shared_ptr<PizzaIngredientFactory> _factory = std::make_shared<ChicagoPizzaIngredientFactory>();

		if (type == ePizzaType::eCheese) {
			return std::make_shared<CheesePizza>(_factory);
		}
		else if (type == ePizzaType::ePepporoni) {
			return std::make_shared<ClamPizza>(_factory);
		}
		else if (type == ePizzaType::eClam) {
			std::cout << "ChicagoStyleClamPizza not implemented yet" << std::endl;
		}
		else if (type == ePizzaType::eVeggie) {
			std::cout << "ChicagoStyleVeggiePizza not implemented yet" << std::endl;
		}
		else {
			std::cout << "wrong pizza type" << std::endl;
		}
	}
};


//old implementation for factory method pattern
//#include "PizzaStore.h"
//#include "ChicagoStyleCheesePizza.h"
//#include "ChicagoStylePepporoniPizza.h"
//
//class ChicagoPizzaStore : public PizzaStore
//{
//public:
//
//	std::shared_ptr<Pizza> createPizza(ePizzaType type) override {
//		if (type == ePizzaType::eCheese) {
//			return std::make_shared<ChicagoStyleCheesePizza>();
//		}
//		else if (type == ePizzaType::ePepporoni) {
//			return std::make_shared<ChicagoStylePepporoniPizza>();
//		}
//		else if (type == ePizzaType::eClam) {
//			std::cout << "ChicagoStyleClamPizza not implemented yet" << std::endl;
//		}
//		else if (type == ePizzaType::eVeggie) {
//			std::cout << "ChicagoStyleVeggiePizza not implemented yet" << std::endl;
//		}
//		else {
//			std::cout << "wrong pizza type" << std::endl;
//		}
//	}
//};
