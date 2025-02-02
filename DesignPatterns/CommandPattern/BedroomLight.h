#pragma once

#include "Light.h"
#include <iostream>

class BedroomLight : public Light
{

public:

	void on() override
	{
		std::cout << "Bedroom light is ON" << std::endl;
	}

	void off() override
	{
		std::cout << "Bedroom light is OFF" << std::endl;
	}
};