#pragma once

#include <iostream>

class CaffieneBeverage
{

public:

	CaffieneBeverage() = default;

	virtual ~CaffieneBeverage() = default;

	virtual void prepareRecipe() final
	{
		boilWater();
		brew();
		pourInCup();
		addCondiments();
	}

	virtual void brew() = 0;

	virtual void addCondiments() = 0;

	void boilWater()
	{
		std::cout << "boiling water" << std::endl;
	}

	void pourInCup()
	{
		std::cout << "Pouring in cup" << std::endl;
	}
};