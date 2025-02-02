#pragma once

#include "Pepporoni.h"

class SlicedPepporoni : public Pepporoni
{
	std::string getName() override {
		return "SlicedPepporoni";
	}
};