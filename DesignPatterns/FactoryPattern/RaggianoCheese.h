#pragma once

#include "Cheese.h"

class RaggianoCheese : public Cheese
{
	std::string getName() override {
		return "RaggianoCheese";
	}
};