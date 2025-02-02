#pragma once

#include <memory>

#include "Sauce.h"
#include "Dough.h"
#include "Cheese.h"
#include "Pepporoni.h"
#include "Clams.h"

class PizzaIngredientFactory {

public:

	virtual std::shared_ptr<Dough> createDough()= 0;
	virtual std::shared_ptr<Sauce> createSauce() = 0;
	virtual std::shared_ptr<Cheese> createCheese() = 0;
	virtual std::shared_ptr<Pepporoni> createPepporoni() = 0;
	virtual std::shared_ptr<Clams> createClams() = 0;
};