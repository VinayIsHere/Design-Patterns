#pragma once

#include "MenuItem.h"
#include <memory>
#include <iostream>
#include "Iterator.h"
#include "DinerMenuIterator.h"
#include "Menu.h"

#define DINER_MAX_ITEMS 6

class DinerMenu: public Menu
{
public:

	DinerMenu()
	{
		addItem("Vegetarian BLT", "(Facon) Bacon with lettuce & tomato on whole wheat", true, 2.99);
		addItem("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99);
		addItem("Soup of the day", "Soup of the day, with a side of potato slide", false, 3.29);
	}
	
	void addItem(std::string name, std::string description, bool veg, double price)
	{
		if (numberOfItems >= DINER_MAX_ITEMS) {
			std::cout << "Sorry, Menu is full!, Can't add item to menu"<<std::endl;
		}
		else
		{
			menuItems[numberOfItems] = std::make_shared<MenuItem>(name, description, veg, price);
			numberOfItems += 1;
		}
	}

	std::shared_ptr<Iterator> CreateIterator() override
	{
		return std::static_pointer_cast<Iterator>(std::make_shared<DinerMenuIterator>(menuItems));
	}

	std::string MenuName() override
	{
		return "Diner Menu";
	}

private:
	int numberOfItems{ 0 };
	std::shared_ptr<MenuItem> menuItems[DINER_MAX_ITEMS];
};