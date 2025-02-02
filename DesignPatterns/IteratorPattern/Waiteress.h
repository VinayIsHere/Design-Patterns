#pragma once

#include "PancakeHouseMenu.h"
#include "DinerMenu.h"
#include <iostream>
#include "Iterator.h"
#include "Menu.h"
#include <memory>

class Waitress
{
		
public:

	Waitress(std::vector<std::shared_ptr<Menu>> menus) : _menus(menus) {}

	void printMenu()
	{
		for (std::shared_ptr<Menu> menu : _menus)
		{
			std::cout << "********** " << menu.get()->MenuName() << " ***************"<<std::endl;
			printMenu(menu);
		}
	}

	void printMenu(std::shared_ptr<Menu> menu)
	{
		auto it = menu.get()->CreateIterator();

		while (it->hasNext())
		{
			std::shared_ptr<MenuItem> item = it->next();
			std::cout << "--------------------ITEM------------------------" << std::endl;
			std::cout << "Name:" << item->getName() << std::endl;
			std::cout << "Description:" << item->getDescription() << std::endl;
			std::cout << "Price:" << item->getPrice() << std::endl;
			std::cout << "IsVegetarian:" << item->isVegetarian() << std::endl;
		}
	}

private:
	std::vector<std::shared_ptr<Menu>> _menus;
};