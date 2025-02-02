#pragma once

#include "Pizza.h"
#include <iostream>

class ClamPizza : public Pizza
{
	std::shared_ptr<PizzaIngredientFactory> _ingredientFactory;

public:

	ClamPizza(std::shared_ptr<PizzaIngredientFactory> ingredientFactory) : _ingredientFactory(ingredientFactory)
	{
	}

	void prepare() override {
		dough = _ingredientFactory.get()->createDough();
		sauce = _ingredientFactory.get()->createSauce();
		cheese = _ingredientFactory.get()->createCheese();
		pepporoni = _ingredientFactory.get()->createPepporoni();
		clams = _ingredientFactory.get()->createClams();

		std::cout << "Preparing Clam Pizza" << std::endl;
		std::cout << "Dough:" << dough.get()->getName() << std::endl;
		std::cout << "Cheese:" << cheese.get()->getName() << std::endl;
		std::cout << "Sauce:" << sauce.get()->getName() << std::endl;
		std::cout << "Pepporoni:" << pepporoni.get()->getName() << std::endl;
		std::cout << "Clams:" << clams.get()->getName() << std::endl;
	}

	void bake() override {
		std::cout << "Baking Clam pizza" << std::endl;
	}

	void cut() override {
		std::cout << "Cutting Clam pizza in circle pieces" << std::endl;
	}

	void box() override {
		std::cout << "Boxing Clam pizza" << std::endl;
	}
};