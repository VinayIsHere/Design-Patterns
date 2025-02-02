#pragma once

#include "CeilingFan.h"
#include <iostream>

class LivingRoomCeilingFan : public CeilingFan
{
public:

	void on() override
	{
		std::cout << "Living room ceiling fan is ON" << std::endl;
	}
	
	void fanOff() override
	{
		std::cout << "Living room ceiling fan is OFF" << std::endl;
	}
};