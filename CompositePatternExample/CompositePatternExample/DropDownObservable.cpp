#include "DropDownObservable.h"

void DropDownObservable::registerRootObserver(std::shared_ptr<IObserver> observer)
{
	m_RootObservers.push_back(observer);
}

void DropDownObservable::registerChildObserver(std::shared_ptr<IObserver> observer)
{
	m_ChildObservers.push_back(observer);
}

void DropDownObservable::unregisterObserver(std::shared_ptr<IObserver> observer)
{
	auto it = std::find(m_RootObservers.begin(), m_RootObservers.end(), observer);

	if (it != m_RootObservers.end())
	{
		m_RootObservers.erase(it);
	}
	else
	{
		auto it = std::find(m_ChildObservers.begin(), m_ChildObservers.end(), observer);

		if (it != m_ChildObservers.end())
		{
			m_ChildObservers.erase(it);
		}
		else
		{
			throw std::logic_error("Component not found in the drop down");
		}
	}
}

void DropDownObservable::notifyChildObservers(eState state)
{
	for (auto observer : m_ChildObservers)
	{
		observer.get()->onNotifiedByParent(state);
	}
}

void DropDownObservable::notifyRootObservers(eState state)
{
	for (auto observer : m_RootObservers)
	{
		observer.get()->onNotifiedByChild(state);
	}
}

void DropDownObservable::notifyAllObservers(eState state)
{
	notifyChildObservers(state);
	notifyRootObservers(state);
}