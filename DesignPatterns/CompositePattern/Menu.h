#pragma once

#include "MenuComponent.h"
#include <vector>
#include <memory>

class Menu: public MenuComponent
{
public:

	Menu(std::string name, std::string description)
		: _name(name), _description(description)
	{}

	void add(std::shared_ptr<MenuComponent> menuComponent) override
	{
		_menuComponents.push_back(menuComponent);
	}

	void remove(std::shared_ptr<MenuComponent> menuComponent) override
	{
		_menuComponents.erase(std::remove(_menuComponents.begin(), _menuComponents.end(), menuComponent));
	}

	std::shared_ptr<MenuComponent> getChild(int i) override
	{
		if(i< _menuComponents.size() && i>0)
			return _menuComponents[i];

		throw std::out_of_range("menu index is out of range");
	}

	std::string getName() override
	{
		return _name;
	}

	std::string getDescription() override
	{
		return _description;
	}

	void print() override
	{
		std::cout << std::endl;
		std::cout << " ******************** " << getName() << " ******************** " << std::endl;
		std::cout << " " << getDescription() << " "<<std::endl;
		std::cout << "-------------------------------"<< std::endl;

		for (std::shared_ptr<MenuComponent> menuComponent : _menuComponents)
		{
			menuComponent.get()->print();
		}
	}

private:

	std::vector<std::shared_ptr<MenuComponent>> _menuComponents;
	std::string _name;
	std::string _description;
};