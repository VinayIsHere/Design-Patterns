#pragma once

#include "Iterator.h"
#include "map"
#include "memory"
#include "MenuItem.h"
#include <iostream>
#include <exception>

class CoffeeMenuIterator : public Iterator
{
public:

	CoffeeMenuIterator(std::map<std::string, std::shared_ptr<MenuItem>> menu)
	{
		_menu = menu;
		_current = _menu.begin();
	}

	std::shared_ptr<MenuItem> next() override
	{
		if (hasNext() == false) {
			std::cout << "No Items Left in coffee" << std::endl;
			throw std::out_of_range("No Items Left in coffee");
		}

		return (_current++)->second;
	}

	bool hasNext()
	{
		return _current != _menu.end();
	}

private:

	std::map<std::string, std::shared_ptr<MenuItem>> _menu;
	std::map<std::string, std::shared_ptr<MenuItem>>::iterator _current;
};