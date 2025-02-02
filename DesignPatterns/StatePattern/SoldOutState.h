#pragma once

#include "State.h"
#include "GumballMachine.h"
#include <memory>
#include <iostream>

class SoldOutState : public State
{
public:

	SoldOutState(std::shared_ptr<GumballMachine> gumballMachine)
	{
		_gumballMachine = gumballMachine;
	}

	void InsertQuarter() override
	{
		std::cout << "You can't insert another quarter" << std::endl;
	}

	void EjectQuarter() override
	{
		std::cout << "You can't eject, you haven't inserted a quarter yet" << std::endl;
	}

	void TurnCrank() override
	{
		std::cout << "You turned but there's no quarter" << std::endl;
	}

	void Dispense() override
	{
		std::cout << "No Gumballs Dispensed" << std::endl;
	}

private:

	std::shared_ptr<GumballMachine> _gumballMachine;
};