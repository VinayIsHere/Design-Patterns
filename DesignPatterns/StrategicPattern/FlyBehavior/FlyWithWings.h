#pragma once

#include "IFlyBehavior.h"
#include <iostream>

class FlyWithWings : public IFlyBehavior
{
public:

	void fly() override
	{
		std::cout << "I'm flying" << std::endl;
	}
};