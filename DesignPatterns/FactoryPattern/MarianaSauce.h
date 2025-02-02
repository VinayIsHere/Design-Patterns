#pragma once

#include "Sauce.h"

class MarianaSauce : public Sauce
{
	std::string getName() override {
		return "MarianaSauce";
	}

};