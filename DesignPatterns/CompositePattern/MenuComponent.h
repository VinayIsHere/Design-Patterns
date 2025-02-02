#pragma once

#include <memory>
#include <exception>
#include <iostream>

class MenuComponent
{
public:

	virtual void add(std::shared_ptr<MenuComponent> menuComponent)
	{
		throw std::logic_error("Unsupported Operation");
	}
	
	virtual void remove(std::shared_ptr<MenuComponent> menuComponent)
	{
		throw std::logic_error("Unsupported Operation");
	}
	
	virtual std::shared_ptr<MenuComponent> getChild(int i)
	{
		throw std::logic_error("Unsupported Operation");
	}

	virtual std::string getName()
	{
		throw std::logic_error("Unsupported Operation");
	}

	virtual std::string getDescription()
	{
		throw std::logic_error("Unsupported Operation");
	}

	virtual double getPrice()
	{
		throw std::logic_error("Unsupported Operation");
	}

	virtual bool isVegetarian()
	{
		throw std::logic_error("Unsupported Operation");
	}

	virtual void print()
	{
		throw std::logic_error("Unsupported Operation");
	}
};