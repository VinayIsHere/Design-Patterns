#pragma once

#include "IObserver.h"
#include "memory"
#include "StateEnum.h"

class IObservable
{
public:

	virtual void registerRootObserver(std::shared_ptr<IObserver> observer) = 0;
	virtual void registerChildObserver(std::shared_ptr<IObserver> observer) = 0;
	
	virtual void unregisterObserver(std::shared_ptr<IObserver> observer) = 0;
	virtual void notifyChildObservers(eState state) = 0;
	virtual void notifyRootObservers(eState state) = 0;
	virtual void notifyAllObservers(eState state) = 0;
};