#pragma once
#include "IDropDownComponent.h"
#include "vector"

class DropDownItem :
    public IDropDownComponent
{

public:

	DropDownItem(std::string itemName): IDropDownComponent(itemName)
	{
	}

	~DropDownItem() = default;

	void add(std::shared_ptr<IDropDownComponent> dropDownComponent) override;
	void remove(std::shared_ptr<IDropDownComponent> dropDownComponent) override;
	void turnOn() override;
	void turnOff() override;

	void onNotifiedByChild(eState state) override;
	void onNotifiedByParent(eState state) override;

private:
	std::vector<std::shared_ptr<IDropDownComponent>> m_childrenDropDownItems;
};

