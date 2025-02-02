#pragma once

#include "Iterator.h"
#define DINER_MAX_ITEMS 6

class DinerMenuIterator: public Iterator
{
public:

	DinerMenuIterator(std::shared_ptr<MenuItem>* items)
	{
		_items = items;
	}

	bool hasNext() override
	{
		if (_position >= DINER_MAX_ITEMS || _items[_position] == nullptr) return false;

		return true;
	}

	std::shared_ptr<MenuItem> next() override
	{
		if (_items[_position] != nullptr)
		{
			std::shared_ptr<MenuItem> item = _items[_position];
			_position += 1;
			return item;
		}
	}

private:
	int _position{0};
	std::shared_ptr<MenuItem>* _items;
};