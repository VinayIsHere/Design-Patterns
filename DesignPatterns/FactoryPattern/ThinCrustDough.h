#pragma once

#include "Dough.h"

class ThinCrustDough : public Dough {
	std::string getName() override {
		return "ThinCrustDough";
	}
};