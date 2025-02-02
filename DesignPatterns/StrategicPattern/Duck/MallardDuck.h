#pragma once

#include "IDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"
#include "FlyNoWay.h"

class MallardDuck : public IDuck
{
public:
	
	MallardDuck() {
		quackBehavior = std::make_shared<Quack>();
		flyBehavior = std::make_shared<FlyNoWay>();
	}

	void display() override
	{
		std::cout << "I am a real Mallard Duck"<<std::endl;
	}
};