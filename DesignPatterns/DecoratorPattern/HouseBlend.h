#pragma once

#include "Beverage.h"

class HouseBlend : public Beverage
{
public:

	HouseBlend() {
		description = "HouseBlend";
	}

	double cost() {
		return 0.89;
	}
};