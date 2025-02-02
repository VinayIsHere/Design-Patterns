#pragma once

#include "PizzaStore.h"
#include "CheesePizza.h"
#include "ClamPizza.h"
#include "NYPizzaIngredientFactory.h"

class NYPizzaStore : public PizzaStore
{
public:

	std::shared_ptr<Pizza> createPizza(ePizzaType type) override {

		std::shared_ptr<PizzaIngredientFactory> _factory = std::make_shared<NYPizzaIngredientFactory>();

		if (type == ePizzaType::eCheese) {
			return std::make_shared<CheesePizza>(_factory);
		}
		else if (type == ePizzaType::eClam) {
			return std::make_shared<ClamPizza>(_factory);
		}
		else if (type == ePizzaType::ePepporoni) {
			std::cout << "Pepporoni Pizza not implemented yet" << std::endl;
		}
		else if (type == ePizzaType::eVeggie) {
			std::cout << "NYStyleVeggiePizza not implemented yet" << std::endl;
		}
		else {
			std::cout << "wrong pizza type" << std::endl;
		}
	}
};


//older version with factory method pattern
//#include "PizzaStore.h"
//#include "NYStyleCheesePizza.h"
//#include "NyStylePepporoniPizza.h"
//
//class NYPizzaStore : public PizzaStore
//{
//public:
//
//	std::shared_ptr<Pizza> createPizza(ePizzaType type) override {
//		if (type == ePizzaType::eCheese) {
//			return std::make_shared<NYStyleCheesePizza>();
//		}
//		else if(type == ePizzaType::ePepporoni){
//			return std::make_shared<NYStlePepporoniPizza>();
//		}
//		else if (type == ePizzaType::eClam) {
//			std::cout << "NYStyleClamPizza not implemented yet" << std::endl;
//		}
//		else if (type == ePizzaType::eVeggie) {
//			std::cout << "NYStyleVeggiePizza not implemented yet" << std::endl;
//		}
//		else {
//			std::cout << "wrong pizza type" << std::endl;
//		}
//	}
//};
