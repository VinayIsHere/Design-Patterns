#pragma once

#include "CaffeineBeverage.h"

class Coffee : public CaffieneBeverage
{
public:

	void brew() override
	{
		std::cout << "Dripping coffee through filter" << std::endl;
	}

	void addCondiments() override
	{
		std::cout << "Adding sugar and milk" << std::endl;
	}
};