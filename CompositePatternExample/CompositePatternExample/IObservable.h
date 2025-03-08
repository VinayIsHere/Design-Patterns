#pragma once

#include "IObserver.h"
#include "memory"

class IObservable
{
public:

	virtual void registerRootObserver(std::shared_ptr<IObserver> observer) = 0;
	virtual void registerChildObserver(std::shared_ptr<IObserver> observer) = 0;
	
	virtual void unregisterObserver(std::shared_ptr<IObserver> observer) = 0;
	virtual void notifyChildObservers(bool state) = 0;
	virtual void notifyRootObservers(bool state) = 0;
	virtual void notifyAllObservers(bool state) = 0;
};