// CompositePatternExample.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "IDropDownComponent.h"
#include "DropDownItem.h"

int main()
{
	std::shared_ptr<IDropDownComponent> rootItem = std::static_pointer_cast<IDropDownComponent>(std::make_shared<DropDownItem>("Root"));

	std::shared_ptr<IDropDownComponent> groupItem1 = std::static_pointer_cast<IDropDownComponent>(std::make_shared<DropDownItem>("Group1"));
	
	std::shared_ptr<IDropDownComponent> item1 = std::static_pointer_cast<IDropDownComponent>(std::make_shared<DropDownItem>("Item1"));
	item1.get()->registerRootObserver(groupItem1);

	std::shared_ptr<IDropDownComponent> item2 = std::static_pointer_cast<IDropDownComponent>(std::make_shared<DropDownItem>("Item2"));
	item2.get()->registerRootObserver(groupItem1);

	groupItem1.get()->add(item1);
	groupItem1.get()->add(item2);
	groupItem1.get()->registerRootObserver(rootItem);

	rootItem.get()->add(groupItem1);
	
	std::shared_ptr<IDropDownComponent> groupItem2 = std::static_pointer_cast<IDropDownComponent>(std::make_shared<DropDownItem>("Group2"));
	std::shared_ptr<IDropDownComponent> item3 = std::static_pointer_cast<IDropDownComponent>(std::make_shared<DropDownItem>("Item3"));
	item3.get()->registerRootObserver(groupItem2);

	std::shared_ptr<IDropDownComponent> item4 = std::static_pointer_cast<IDropDownComponent>(std::make_shared<DropDownItem>("Item4"));
	item4.get()->registerRootObserver(groupItem2);

	groupItem2.get()->add(item3);
	groupItem2.get()->add(item4);
	groupItem2.get()->registerRootObserver(rootItem);

	rootItem.get()->add(groupItem2);

	//test Case
	std::cout << "************************* Operation *************************" << std::endl;
	item1.get()->turnOn();
	item2.get()->turnOn();

	item3.get()->turnOn();
	item4.get()->turnOn();
}