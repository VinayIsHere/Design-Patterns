#pragma once

#include "ICommand.h"
#include "CeilingFan.h"
#include "memory"

class CeilingFanHighCommand : public ICommand
{

public:

	CeilingFanHighCommand(std::shared_ptr<CeilingFan> fan)
	{
		_ceilingFan = fan;
	}

	void execute() override
	{
		_prevSpeed = _ceilingFan.get()->getSpeed();
		_ceilingFan.get()->high();
	}

	void undo() override
	{
		if (_prevSpeed == HIGH)
		{
			_ceilingFan.get()->high();
		}
		else if (_prevSpeed == MEDIUM)
		{
			_ceilingFan.get()->medium();
		}
		else if (_prevSpeed == LOW)
		{
			_ceilingFan.get()->low();
		}
		else if (_prevSpeed == OFF) {
			_ceilingFan.get()->off();
		}
	}

private:

	std::shared_ptr<CeilingFan> _ceilingFan;
	int _prevSpeed;
};