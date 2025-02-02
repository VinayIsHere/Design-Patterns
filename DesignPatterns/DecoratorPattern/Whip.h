#pragma once

#include "CondimentDecorator.h"

class Whip : public CondimentDecorator
{
public:

	Whip(std::shared_ptr<Beverage> beverage) {
		this->beverage = beverage;
	}

	std::string getDescription() {
		return beverage.get()->getDescription() + ", Whip";
	}

	double cost() {
		return beverage.get()->cost() + 0.33;
	}
};