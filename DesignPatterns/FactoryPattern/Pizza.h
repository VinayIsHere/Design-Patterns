#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <utility>

#include "Dough.h"
#include "Cheese.h"
#include "Clams.h"
#include "Sauce.h"
#include "Pepporoni.h"

enum class ePizzaType {
	eCheese,
	ePepporoni,
	eClam,
	eVeggie
};

class Pizza
{
public:

	std::string name;

	std::shared_ptr<Dough> dough;
	std::shared_ptr<Cheese> cheese;
	std::shared_ptr<Pepporoni> pepporoni;
	std::shared_ptr<Clams> clams;
	std::shared_ptr<Sauce> sauce;

	virtual void prepare() = 0;

	virtual void bake() {
		std::cout << "Bake for 25 minutes at 350" << std::endl;
	}

	virtual void cut() {
		std::cout << "Cutting the pizza into diagonal shapes" << std::endl;
	}

	virtual void box() {
		std::cout << "Place pizza in official pizzabox store" << std::endl;
	}

	std::string getName() {
		return name;
	}
};