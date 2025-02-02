#pragma once

#include "ICommand.h"
#include <vector>
#include <memory>
#include "NoCommand.h"
#include <iostream>

using namespace std;

//no of controls, remote have
#define REMOTE_COMMANDS_SIZE 7

class RemoteControl
{
public:

	RemoteControl(){
		for (int i = 0; i < REMOTE_COMMANDS_SIZE; i++)
		{
			_onCommands.push_back(std::make_shared<NoCommand>());
			_offCommands.push_back(std::make_shared<NoCommand>());
		}

		_undoCommand = std::make_shared<NoCommand>();
	}

	void setCommand(int slot, std::shared_ptr<ICommand> onCommand, std::shared_ptr<ICommand> offCommand) 
	{
		_onCommands.insert(_onCommands.begin() + slot, onCommand);
		_offCommands.insert(_offCommands.begin() + slot, offCommand);
	}

	void onButtonPressed(int slot)
	{
		if ((_onCommands.size() < slot) && (slot > 0) == false) {
			cout << "wrong index" << std::endl;
		}

		_onCommands[slot].get()->execute();
		_undoCommand = _onCommands[slot];
	}

	void offButtonPressed(int slot)
	{
		if ((_offCommands.size() < slot) && (slot > 0) == false) {
			cout << "wrong index" << std::endl;
		}

		_offCommands[slot].get()->execute();
		_undoCommand = _offCommands[slot];
	}

	void undoButtonPressed()
	{
		_undoCommand.get()->undo();
	}

private:

	vector<shared_ptr<ICommand>> _onCommands;
	vector<shared_ptr<ICommand>> _offCommands;
	shared_ptr<ICommand> _undoCommand;
};