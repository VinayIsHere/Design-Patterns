#pragma once

#include "Clams.h"

class FreshClams : public Clams
{
public:
	std::string getName() override{
		return "FreshClams";
	}
};