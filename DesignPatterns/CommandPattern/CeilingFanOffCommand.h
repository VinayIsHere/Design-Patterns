#pragma once

#include "ICommand.h"
#include "CeilingFan.h"
#include <memory>

class CeilingFanOffCommand : public ICommand
{
public:

	CeilingFanOffCommand(std::shared_ptr<CeilingFan> fan)
	{
		_fan = fan;
	}

	void execute() override
	{
		_fan.get()->off();
		_fan.get()->fanOff();
	}

	void undo() override {
		_fan.get()->on();
	}

private:

	std::shared_ptr<CeilingFan> _fan;
};