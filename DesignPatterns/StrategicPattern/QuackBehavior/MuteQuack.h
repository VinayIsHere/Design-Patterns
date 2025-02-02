#pragma once

#include "IQuackBehavior.h"
#include <iostream>

class MuteQuack : public IQuackBehavior
{
public:

	void quack() override
	{
		std::cout << "Silence" << std::endl;
	}
};