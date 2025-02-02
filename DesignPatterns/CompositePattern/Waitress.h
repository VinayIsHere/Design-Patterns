#pragma once

#include "MenuComponent.h"
#include <memory>

class Waitress
{
public:

	Waitress(std::shared_ptr<MenuComponent> allMenus)
	{
		_allMenus=allMenus;
	}

	void printMenu()
	{
		_allMenus.get()->print();
	}

private:
	std::shared_ptr<MenuComponent> _allMenus;
};