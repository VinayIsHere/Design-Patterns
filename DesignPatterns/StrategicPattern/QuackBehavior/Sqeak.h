#pragma once

#include "IQuackBehavior.h"
#include <iostream>

class Sqeak : public IQuackBehavior
{
public:

	void quack() override
	{
		std::cout << "Sqeak" << std::endl;
	}
};