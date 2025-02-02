#pragma once

#include "MenuComponent.h"
#include <iostream>

class MenuItem : public MenuComponent
{
public:

	MenuItem(std::string name,
		std::string description,
		bool veg,
		double price)
		: _name(name), _description(description), _veg(veg), _price(price)
	{}
	
	std::string getName() override
	{
		return _name;
	}

	std::string getDescription() override
	{
		return _description;
	}

	bool isVegetarian() override
	{
		return _veg;
	}

	double getPrice() override
	{
		return _price;
	}

	void print() override
	{
		std::cout<<std::endl;
		std::cout <<" " + getName() + " ";
		
		if (isVegetarian())
		{
			std::cout << " (v) ";
		}
		std::cout << ", "<<getPrice();
		std::cout << "   --" << getDescription();
	}

private:

	std::string _name;
	std::string _description;
	bool _veg;
	double _price;
};