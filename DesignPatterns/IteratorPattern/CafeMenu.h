#pragma once

#include "Menu.h"
#include "MenuItem.h"
#include "map"
#include "CoffeeMenuIterator.h"

class CafeMenu : public Menu
{
public:

	CafeMenu()
	{
		addItem("Coffee", "A Simple Coffee", true, 2.99);
		addItem("Mocha", "Coffee with white Mocha", true, 3.99);
		addItem("Cappachino", "A Cappichino coffee", true, 3.99);
	}

	void addItem(std::string name, std::string description, bool veg, double price)
	{
		std::shared_ptr<MenuItem> item = std::make_shared<MenuItem>(name, description, veg, price);
		_menuItems[name] = item;
	}

	std::shared_ptr<Iterator> CreateIterator() override
	{
		return std::static_pointer_cast<Iterator>(std::make_shared<CoffeeMenuIterator>(_menuItems));
	}
	
	std::string MenuName() override
	{
		return "Cafe Menu";
	}

private:
	std::map<std::string, std::shared_ptr<MenuItem>> _menuItems;
};