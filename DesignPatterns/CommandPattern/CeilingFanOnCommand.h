#pragma once

#include "ICommand.h"
#include "CeilingFan.h"
#include <memory>

class CeilingFanOnCommand : public ICommand
{
public:

	CeilingFanOnCommand(std::shared_ptr<CeilingFan> fan)
	{
		_fan = fan;
	}
	
	void execute() override 
	{
		_fan.get()->on();
		_fan.get()->low();
	}

	void undo() override
	{
		_fan.get()->off();
	}

private:

	std::shared_ptr<CeilingFan> _fan;
};