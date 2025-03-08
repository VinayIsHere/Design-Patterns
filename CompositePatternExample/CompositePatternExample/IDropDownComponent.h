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

	eState getCheckedState()
	{
		return m_checkedState;
	}

	std::string getItemName()
	{
		return m_itemName;
	}

protected:

	void setCheckedState(eState state)
	{
		if (m_checkedState == state)
		{
			std::cout << getItemName() << " state already same, currentState:" << static_cast<int>(getCheckedState()) << ", newState:" << static_cast<int>(state) << std::endl;
			return;
		}

		std::cout << getItemName() << " StateChanged:" << static_cast<int>(state)<< std::endl;
		m_checkedState = state;
	}

	std::string m_itemName;
	eState m_checkedState{ eState::E_OFF};
};