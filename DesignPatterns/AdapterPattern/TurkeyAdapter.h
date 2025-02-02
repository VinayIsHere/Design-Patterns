#pragma once

#include "../StrategicPattern/Duck/Interface/IDuck.h"
#include "../StrategicPattern/FlyBehavior/Interface/IFlyBehavior.h"
#include "../StrategicPattern/QuackBehavior/Interface/IQuackBehavior.h"
#include "Turkey.h"
#include "memory"

class TurkeyAdapter : public IDuck, public IQuackBehavior, public IFlyBehavior
{
public:

	TurkeyAdapter(std::shared_ptr<Turkey> turkey)
	{
		_turkey = turkey;
	}

	void quack() override
	{
		_turkey.get()->gobble();
	}

	void fly() override
	{
		for (int i = 0; i < 5; i++)
		{
			_turkey.get()->fly();
		}
	}

	void display() override
	{
		std::cout << "turket wrapped as duck" << std::endl;
	}

private:
	std::shared_ptr<Turkey> _turkey;
};
