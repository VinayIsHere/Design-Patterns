#pragma once

#include "IQuackBehavior.h"
#include <iostream>

class Quack : public IQuackBehavior
{
public:
	
	void quack() override
	{
		std::cout << "Quack" << std::endl;
	}
};