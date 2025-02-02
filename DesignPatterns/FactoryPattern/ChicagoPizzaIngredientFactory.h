#pragma once

#include "PizzaIngredientFactory.h"
#include "ThickCrustDough.h"
#include "MozzarellaCheese.h"
#include "PlumTomatoSauce.h"
#include "SlicedPepporoni.h"
#include "FrozenClams.h"

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory
{
public:

	std::shared_ptr<Dough> createDough() {
		return std::make_shared<ThickCrustDough>();
	}

	std::shared_ptr<Sauce> createSauce() {
		return std::make_shared<PlumTomatoSauce>();
	}

	std::shared_ptr<Cheese> createCheese() {
		return std::make_shared<MozzarellaCheese>();
	}

	std::shared_ptr<Pepporoni> createPepporoni() {
		return std::make_shared<SlicedPepporoni>();
	}

	std::shared_ptr<Clams> createClams() {
		return std::make_shared<FrozenClams>();
	}

};