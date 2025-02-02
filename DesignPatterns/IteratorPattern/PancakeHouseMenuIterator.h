#pragma once

#include "Iterator.h"
#include "vector"
#include "memory"
#include "iostream"
#include <exception>

class PancakeHouseMenuIterator : public Iterator
{
public:

	PancakeHouseMenuIterator(std::vector<std::shared_ptr<MenuItem>> items)
	{
		_items = items;
		_currentIndex = 0;
	}

	bool hasNext() override
	{
		return _currentIndex < _items.size();
	}

	std::shared_ptr<MenuItem> next() override
	{
		if (hasNext() == false)
		{
			std::cout<< "No More Items left";
			throw std::out_of_range("No More Items left");
		}
		
		return _items[_currentIndex++];
	}

private:

	std::vector<std::shared_ptr<MenuItem>> _items;
	std::shared_ptr<MenuItem> _currentItem;
	size_t _currentIndex{0};
};