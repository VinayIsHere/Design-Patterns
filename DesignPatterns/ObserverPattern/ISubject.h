#pragma once

#include "IObserver.h"
#include <memory>

class ISubject
{
public:

	virtual void registerObserver(std::shared_ptr<IObserver> o)= 0;
	virtual void removeObserver(std::shared_ptr<IObserver> o)= 0;
	virtual void notifyObservers()= 0;
};