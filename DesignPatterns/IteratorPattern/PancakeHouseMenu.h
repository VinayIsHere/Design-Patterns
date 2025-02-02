#pragma once

#include "MenuItem.h"
#include <vector>
#include <memory>
#include "Iterator.h"
#include "PancakeHouseMenuIterator.h"
#include "Menu.h"

class PancakeHouseMenu: public Menu
{
public:

	PancakeHouseMenu()
	{
		addItem("K&Bs Pancake breakfast", "Pancake with scrambled eggs and toast", true, 2.99);
		addItem("Regular Pancake breakfast", "Pancake with fried eggs, sausage", true, 2.99);
		addItem("Bluebarry Pancakes", "Pancakes made. with fresh bluebarries", true, 3.49);
		addItem("Waffles", "Waffles with your choice of bluebarries or strawbarries", true, 3.59);
	}

	void addItem(std::string name, std::string description, bool veg, double price)
	{
		_menuItems.push_back(std::make_shared<MenuItem>(name, description, veg, price));
	}

	std::shared_ptr<Iterator> CreateIterator() override
	{
		return std::static_pointer_cast<Iterator>(std::make_shared<PancakeHouseMenuIterator>(_menuItems));
	}

	std::string MenuName() override
	{
		return "Pancake House Menu";
	}

	std::vector<std::shared_ptr<MenuItem>> getMenuItems()
	{
		return _menuItems;
	}

private:
	std::vector<std::shared_ptr<MenuItem>> _menuItems;
};