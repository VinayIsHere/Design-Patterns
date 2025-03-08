#include "DropDownItem.h"

void DropDownItem::add(std::shared_ptr<IDropDownComponent> dropDownComponent)
{
	registerChildObserver(dropDownComponent);
	m_childrenDropDownItems.push_back(dropDownComponent);
}

void DropDownItem::remove(std::shared_ptr<IDropDownComponent> dropDownComponent)
{
	unregisterObserver(dropDownComponent);

	auto it = std::find(m_childrenDropDownItems.begin(), m_childrenDropDownItems.end(), dropDownComponent);

	if (it != m_childrenDropDownItems.end())
	{
		m_childrenDropDownItems.erase(it);
	}
	else
	{
		throw std::logic_error("Component not found in the children");
	}
}

void DropDownItem::turnOn()
{
	std::cout << "\nItem:" << getItemName() << " is turned on" << std::endl;

	setCheckedState(true);
	notifyAllObservers(getCheckedState());
}

void DropDownItem::turnOff()
{
	std::cout << "\nItem:" << getItemName() << " is turned off" << std::endl;

	setCheckedState(false);
	notifyAllObservers(getCheckedState());
}

void DropDownItem::onNotifiedByChild(bool state)
{
	std::cout << getItemName() << " notified by child" << std::endl;

	if (state == false)
	{
		setCheckedState(false);
	}
	else if (state == true)
	{
		bool newState = true;

		for (auto child : m_childrenDropDownItems)
		{
			newState &= child.get()->getCheckedState();
		}

		setCheckedState(newState);
	}
	notifyRootObservers(getCheckedState());
}

void DropDownItem::onNotifiedByParent(bool state)
{
	std::cout << getItemName() << " notified by parent" << std::endl;
	setCheckedState(state);
	notifyChildObservers(getCheckedState());
}