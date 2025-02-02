#pragma once

#include "IFlyBehavior.h"
#include "IQuackBehavior.h"
#include <memory>
#include <iostream>

class IDuck
{
	
public:

	IDuck() = default;

	virtual void display() = 0;

	void performFly()
	{
		flyBehavior.get()->fly();
	}

	void performQuack()
	{
		quackBehavior.get()->quack();
	}

	void setFlyBehavior(std::shared_ptr<IFlyBehavior> fly) {
		flyBehavior = fly;
	}
	
	void setQuackBehavior(std::shared_ptr<IQuackBehavior> quack) {
		quackBehavior = quack;
	}

	void swim()
	{
		std::cout << "all ducks float, even decoys!" << std::endl;
	}

protected:

	std::shared_ptr<IFlyBehavior> flyBehavior;
	std::shared_ptr<IQuackBehavior> quackBehavior;
};