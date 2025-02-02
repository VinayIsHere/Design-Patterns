#pragma once

#include <string>

class MenuItem
{

public:

	MenuItem(std::string name,
		std::string description,
		bool vegetarian,
		double price)
		: _name(name), _description(description), _vegetarian(vegetarian), _price(price)
	{
	}

	std::string getName()
	{
		return _name;
	}

	std::string getDescription()
	{
		return _description;
	}

	bool isVegetarian()
	{
		return _vegetarian;
	}

	double getPrice()
	{
		return _price;
	}

private:
	std::string _name;
	std::string _description;
	bool _vegetarian;
	double _price;
};