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

	setCheckedState(eState::E_ON);
	notifyAllObservers(getCheckedState());
}

void DropDownItem::turnOff()
{
	std::cout << "\nItem:" << getItemName() << " is turned off" << std::endl;

	setCheckedState(eState::E_OFF);
	notifyAllObservers(getCheckedState());
}

void DropDownItem::onNotifiedByChild(eState state)
{
	std::cout << getItemName() << " notified by child" << std::endl;

	if (state == eState::E_UNDETERMINED)
	{
		setCheckedState(state);
		std::cout << "setting state for " << getItemName() << " , state:" << static_cast<int>(getCheckedState()) << std::endl;
	}
	else
	{
		eState eFinalState = state;

		for (auto child : m_childrenDropDownItems)
		{
			if (child.get()->getCheckedState() != eFinalState)
			{
				eFinalState = eState::E_UNDETERMINED;
				break;
			}
		}

		setCheckedState(eFinalState);
		std::cout << "setting state for " << getItemName() << " , state:" << static_cast<int>(getCheckedState()) << std::endl;
	}

	notifyRootObservers(getCheckedState());
}

void DropDownItem::onNotifiedByParent(eState state)
{
	std::cout << getItemName() << " notified by parent" << std::endl;
	setCheckedState(state);
	notifyChildObservers(getCheckedState());
}