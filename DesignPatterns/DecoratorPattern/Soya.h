#pragma once

#include "CondimentDecorator.h"

class Soya : public CondimentDecorator
{
public:

	Soya(std::shared_ptr<Beverage> beverage) {
		this->beverage = beverage;
	}

	std::string getDescription() {
		return beverage.get()->getDescription() + ", Soya";
	}

	double cost() {
		return beverage.get()->cost() + 0.66;
	}
};