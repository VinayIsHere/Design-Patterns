#pragma once

#include "Iterator.h"

class Menu
{
public:
	virtual std::shared_ptr<Iterator> CreateIterator()= 0;
	virtual std::string MenuName() = 0;
};