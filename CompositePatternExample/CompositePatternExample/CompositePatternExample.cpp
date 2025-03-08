// CompositePatternExample.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "IDropDownComponent.h"
#include "DropDownItem.h"
#include <memory>

using namespace std;

void resetState(std::shared_ptr<IDropDownComponent>);
void testCase1(std::shared_ptr<IDropDownComponent>);

int main()
{
	std::shared_ptr<DropDownItem> root = std::make_shared<DropDownItem>("root");

	std::shared_ptr<DropDownItem> group1 = std::make_shared<DropDownItem>("group 1");
	std::shared_ptr<DropDownItem> item1 = std::make_shared<DropDownItem>("item 1");
	std::shared_ptr<DropDownItem> item2 = std::make_shared<DropDownItem>("item 2");

	std::shared_ptr<DropDownItem> group2 = std::make_shared<DropDownItem>("group 2");
	std::shared_ptr<DropDownItem> item3 = std::make_shared<DropDownItem>("item 3");
	std::shared_ptr<DropDownItem> item4 = std::make_shared<DropDownItem>("item 4");

	//establishing parent child relation
	group1.get()->add(static_pointer_cast<IDropDownComponent>(item1));
	group1.get()->add(static_pointer_cast<IDropDownComponent>(item2));

	group2.get()->add(static_pointer_cast<IDropDownComponent>(item3));
	group2.get()->add(static_pointer_cast<IDropDownComponent>(item4));

	root.get()->add(static_pointer_cast<IDropDownComponent>(group1));
	root.get()->add(static_pointer_cast<IDropDownComponent>(group2));

	//setting up root subscriptions
	item1.get()->registerRootObserver(static_pointer_cast<IDropDownComponent>(group1));
	item2.get()->registerRootObserver(static_pointer_cast<IDropDownComponent>(group1));

	item3.get()->registerRootObserver(static_pointer_cast<IDropDownComponent>(group2));
	item4.get()->registerRootObserver(static_pointer_cast<IDropDownComponent>(group2));

	group1.get()->registerRootObserver(static_pointer_cast<IDropDownComponent>(root));
	group2.get()->registerRootObserver(static_pointer_cast<IDropDownComponent>(root));

	//setting all states to off;
	resetState(static_pointer_cast<IDropDownComponent>(root));

	//test case 1: setting root to on, should turn all children in on state
	std::cout << "***************** TEST CASE 1 *****************" << std::endl;
	testCase1(static_pointer_cast<IDropDownComponent>(root));


	resetState(static_pointer_cast<IDropDownComponent>(root));
	//test case 2: setting item 3 to on, should make group2 and root state as unterministic
	std::cout << "***************** TEST CASE 2 *****************" << std::endl;
	item3.get()->turnOn();
	
	resetState(static_pointer_cast<IDropDownComponent>(root));
	//test case 2: it should set the group2 state to on, but root state as undeterministic.
	std::cout << "***************** TEST CASE 3 *****************" << std::endl;
	item3.get()->turnOn();
	item4.get()->turnOn();

	return 0;
}

void resetState(std::shared_ptr<IDropDownComponent> root)
{
	root.get()->turnOff();
}

void testCase1(std::shared_ptr<IDropDownComponent> root)
{
	root.get()->turnOn();
}