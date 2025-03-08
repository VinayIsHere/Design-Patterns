#pragma once
#include "IObserver.h"
#include "IObservable.h"
#include <exception>
#include <iostream>
#include <vector>

class DropDownObservable : public IObservable
{
public:

	void registerRootObserver(std::shared_ptr<IObserver> observer) override;
	void registerChildObserver(std::shared_ptr<IObserver> observer) override;

	void unregisterObserver(std::shared_ptr<IObserver> observer) override;
	void notifyChildObservers(eState state) override;
	void notifyRootObservers(eState state) override;
	void notifyAllObservers(eState state) override;

private:

	std::vector<std::shared_ptr<IObserver>> m_RootObservers;
	std::vector<std::shared_ptr<IObserver>> m_ChildObservers;
};

