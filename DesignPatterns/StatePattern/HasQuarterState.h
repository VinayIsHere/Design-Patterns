#pragma once

#include "State.h"
#include "GumballMachine.h"
#include <memory>
#include <iostream>
#include <random>

class HasQuarterState : public State
{
public:

	HasQuarterState(std::shared_ptr<GumballMachine> gumballMachine)
	{
		_gumballMachine = gumballMachine;
	}

	void InsertQuarter() override
	{
		std::cout << "You can't insert another quarter" << std::endl;
	}

	void EjectQuarter() override
	{
		std::cout << "Quater Returned" << std::endl;
		_gumballMachine.get()->SetState(_gumballMachine.get()->getNoQuarterState());
	}

	void TurnCrank() override
	{
		std::cout << "You turned...";

		if (isWinner() && _gumballMachine.get()->getGumballsCount() > 1)
		{
			_gumballMachine.get()->SetState(_gumballMachine.get()->getWinnerState());
		}
		else
		{
			_gumballMachine.get()->SetState(_gumballMachine.get()->getSoldState());
		}
	}

	void Dispense() override
	{
		std::cout << "No Dumball Dispensed" << std::endl;
	}

	// Helper method to generate a 10% chance of winning
	bool isWinner()
	{
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(1, 10); // Generate a number between 1 and 10
		return dist(gen) == 5; // 10% chance (number 1 only)
	}

private:

	std::shared_ptr<GumballMachine> _gumballMachine;
};