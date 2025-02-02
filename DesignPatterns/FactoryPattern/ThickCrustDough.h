#pragma once

#include "Dough.h"

class ThickCrustDough : public Dough
{
public:
	std::string getName() {
		return "ThickCrustDough";
	}
};