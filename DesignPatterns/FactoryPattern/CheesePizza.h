#pragma once

#include "Pizza.h"
#include <iostream>
#include "PizzaIngredientFactory.h"

class CheesePizza : public Pizza
{
	std::shared_ptr<PizzaIngredientFactory> _ingredientFactory;

public:

	CheesePizza(std::shared_ptr<PizzaIngredientFactory> ingredientFactory) : _ingredientFactory(ingredientFactory)
	{
	}

	void prepare() override {
		dough = _ingredientFactory.get()->createDough();
		sauce = _ingredientFactory.get()->createSauce();
		cheese = _ingredientFactory.get()->createCheese();
		pepporoni = _ingredientFactory.get()->createPepporoni();
		clams = _ingredientFactory.get()->createClams();

		std::cout << "Preparing Cheese Pizza" << std::endl;
		std::cout << "Dough:" << dough.get()->getName() << std::endl;
		std::cout << "Cheese:" << cheese.get()->getName() << std::endl;
		std::cout << "Sauce:" << sauce.get()->getName() << std::endl;
		std::cout << "Pepporoni:" << pepporoni.get()->getName() << std::endl;
		std::cout << "Clams:" << clams.get()->getName() << std::endl;
	}

	void bake() override {
		std::cout << "Baking Cheese Pizza" << std::endl;
	}

	void cut() override {
		std::cout << "Cutting Cheese Pizza into traingles" << std::endl;
	}

	void box() override {
		std::cout << "Boxing Cheese pizza" << std::endl;
	}
};