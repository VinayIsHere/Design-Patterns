#pragma once

#include "State.h"
#include "GumballMachine.h"
#include <memory>
#include <iostream>

class SoldState : public State
{
public:

	SoldState(std::shared_ptr<GumballMachine> gumballMachine)
	{
		_gumballMachine = gumballMachine;
	}

	void InsertQuarter() override
	{
		std::cout << "Please wait!, we're already giving you a gumball" << std::endl;
	}

	void EjectQuarter() override
	{
		std::cout << " Sorry, You already turned the trank" << std::endl;
	}

	void TurnCrank() override
	{
		std::cout << "Turning crank twice, won't get you another gumball" << std::endl;
	}

	void Dispense() override
	{
		_gumballMachine.get()->ReleaseBall();

		if (_gumballMachine.get()->getGumballsCount() > 0)
		{
			_gumballMachine.get()->SetState(_gumballMachine.get()->getNoQuarterState());
		}
		else
		{
			_gumballMachine.get()->SetState(_gumballMachine.get()->getSoldOutState());
		}
	}

private:

	std::shared_ptr<GumballMachine> _gumballMachine;
};