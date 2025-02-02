#pragma once

#include "Beverage.h"
#include <memory>

class CondimentDecorator : public Beverage
{
protected:
	std::shared_ptr<Beverage> beverage;
};