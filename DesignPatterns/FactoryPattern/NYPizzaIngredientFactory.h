#pragma once

#include "PizzaIngredientFactory.h"

#include "ThinCrustDough.h"
#include "MarianaSauce.h"
#include "RaggianoCheese.h"
#include "SlicedPepporoni.h"
#include "FreshClams.h"

class NYPizzaIngredientFactory : public PizzaIngredientFactory {

	std::shared_ptr<Dough> createDough() {
		return std::make_shared<ThinCrustDough>();
	}

	std::shared_ptr<Sauce> createSauce() {
		return std::make_shared<MarianaSauce>();
	}

	std::shared_ptr<Cheese> createCheese() {
		return std::make_shared<RaggianoCheese>();
	}

	std::shared_ptr<Pepporoni> createPepporoni(){
		return std::make_shared<SlicedPepporoni>();
	}

	std::shared_ptr<Clams> createClams() {
		return std::make_shared<FreshClams>();
	}
};