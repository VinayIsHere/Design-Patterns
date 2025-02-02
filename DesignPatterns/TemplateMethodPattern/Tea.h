#pragma once

#include "CaffeineBeverage.h"

class Tea : public CaffieneBeverage
{

public:

	void brew() override
	{
		std::cout << "Steeping the tea" << std::endl;
	}

	void addCondiments() override
	{
		std::cout << "Adding lemon" << std::endl;
	}
};