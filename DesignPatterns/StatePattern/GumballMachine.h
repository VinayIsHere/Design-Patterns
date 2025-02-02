#pragma once

#include <iostream>
#include "State.h"
#include <memory>

class GumballMachine: public std::enable_shared_from_this<GumballMachine>
{

public:

	GumballMachine(int gumballsCount)
	{
		_gumballsCount = gumballsCount;
	}

	void InitializeStates(std::shared_ptr<State> soldOutState, 
						  std::shared_ptr<State> soldState,
						  std::shared_ptr<State> noQuarterState,
						  std::shared_ptr<State> hasQuarterState,
						  std::shared_ptr<State> winnerState)
	{
		_soldOutState = soldOutState;
		_soldState = soldState;
		_noQuarterState = noQuarterState;
		_hasQuarterState = hasQuarterState;
		_winnerState = winnerState;

		if (_gumballsCount > 0)
		{
			_state = _noQuarterState;
		}
		else
		{
			_state = _soldOutState;
		}
	}

	void InsertQuarter()
	{
		_state.get()->InsertQuarter();
	}

	void EjectQuarter()
	{
		_state.get()->EjectQuarter();
	}

	void TurnCrank()
	{
		_state.get()->TurnCrank();
		_state.get()->Dispense();
	}

	void SetState(std::shared_ptr<State> state)
	{
		_state = state;
	}

	void ReleaseBall()
	{
		std::cout << "A gumball comes rolling out the slot ..."<<std::endl;

		if (_gumballsCount > 0)
		{
			_gumballsCount -= 1;
		}
	}

	int getGumballsCount()
	{
		return _gumballsCount;
	}

	//getters for each state
	std::shared_ptr<State> getHasQuarterState()
	{
		return _hasQuarterState;
	}

	std::shared_ptr<State> getNoQuarterState()
	{
		return _noQuarterState;
	}

	std::shared_ptr<State> getSoldOutState()
	{
		return _soldOutState;
	}

	std::shared_ptr<State> getSoldState()
	{
		return _soldState;
	}

	std::shared_ptr<State> getWinnerState()
	{
		return _winnerState;
	}

private:

	std::shared_ptr<State> _soldOutState;
	std::shared_ptr<State> _noQuarterState;
	std::shared_ptr<State> _hasQuarterState;
	std::shared_ptr<State> _soldState;
	std::shared_ptr<State> _winnerState;

	int _gumballsCount{0};
	std::shared_ptr<State> _state;
};