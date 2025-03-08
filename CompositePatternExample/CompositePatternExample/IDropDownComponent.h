#pragma once

#include <iostream>
#include <exception>
#include <memory>
#include "IObserver.h"
#include "DropDownObservable.h"

class IDropDownComponent: public DropDownObservable, public IObserver
{
public:
	
	IDropDownComponent(std::string itemName): m_itemName(itemName)
	{}

	virtual void add(std::shared_ptr<IDropDownComponent> dropDownComponent) = 0;

	virtual void remove(std::shared_ptr<IDropDownComponent> dropDownComponent) = 0;

	virtual void turnOn() = 0;
	
	virtual void turnOff() = 0;

	virtual ~IDropDownComponent() = default;

	bool getCheckedState()
	{
		return m_checkedState;
	}

	std::string getItemName()
	{
		return m_itemName;
	}

protected:

	void setCheckedState(bool state)
	{
		if (m_checkedState == state)
		{
			std::cout << getItemName() << " state already same, currentState:" << getCheckedState() << ", newState:" << state << std::endl;
			return;
		}

		std::cout << getItemName() << " StateChanged:" << state<< std::endl;
		m_checkedState = state;
	}

	std::string m_itemName;
	bool m_checkedState{false};
};