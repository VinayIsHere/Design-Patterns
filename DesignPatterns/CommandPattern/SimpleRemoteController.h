#pragma once

#include "ICommand.h"
#include <memory>

class SimpleRemoteController
{

public:

	SimpleRemoteController()
	{
	}

	void setCommand(std::shared_ptr<ICommand> command)
	{
		_slot = command;
	}

	void buttonPressed()
	{
		_slot.get()->execute();
	}

private:
	std::shared_ptr<ICommand> _slot;
};