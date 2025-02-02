#pragma once

#include "CondimentDecorator.h"

class Mocha : public CondimentDecorator
{
public:

	Mocha(std::shared_ptr<Beverage> beverage) {
		this->beverage = beverage;
	}

	std::string getDescription() {
		return beverage.get()->getDescription() + ", Mocha";
	}

	double cost() {
		return beverage.get()->cost() + 0.20;
	}
};