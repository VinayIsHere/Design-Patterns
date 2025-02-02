#pragma once

#include <iostream>
#include "IFlyBehavior.h"

class FlyRocketPowered : public IFlyBehavior
{
public:

	void fly() override
	{
		std::cout << "I am flying with a rocket";
	}
};