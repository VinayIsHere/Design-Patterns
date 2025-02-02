#pragma once

#include "ICommand.h"

class NoCommand : public ICommand
{
public:

	void execute() override
	{
		//it does nothing.
	}

	void undo() override
	{
		//it does nothing.
	}
};