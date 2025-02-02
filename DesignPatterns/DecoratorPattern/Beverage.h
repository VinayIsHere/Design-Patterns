#pragma once

#include <string>

class Beverage
{
public:

	Beverage() = default;
	~Beverage() = default;

	std::string description{ "Unknown message" };

	virtual std::string getDescription() {
		return description;
	}

	virtual double cost() = 0;
};