#pragma once

#include "State.h"
#include "GumballMachine.h"
#include <memory>
#include <iostream>

class NoQuarterState : public State
{
public:

	NoQuarterState(std::shared_ptr<GumballMachine> gumballMachine)
	{
		_gumballMachine = gumballMachine;
	}

	void InsertQuarter() override
	{
		std::cout << "You inserted a quarter" << std::endl;
		_gumballMachine.get()->SetState(_gumballMachine.get()->getHasQuarterState());
	}

	void EjectQuarter() override
	{
		std::cout << "You haven't inserted a quarter yet" << std::endl;
	}

	void TurnCrank() override
	{
		std::cout << "You turned, but there's no quarter" << std::endl;
	}

	void Dispense() override
	{
		std::cout << "You need to pay first" << std::endl;
	}

private:

	std::shared_ptr<GumballMachine> _gumballMachine;
};