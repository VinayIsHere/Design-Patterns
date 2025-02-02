#pragma once

#include "Turkey.h"
#include <iostream>

class WildTurkey: public Turkey
{
public:

	void gobble() override
	{
		std::cout << "gobble gobble" << std::endl;
	}

	void fly() override
	{
		std::cout << "I am flying a short distance" << std::endl;
	}
};