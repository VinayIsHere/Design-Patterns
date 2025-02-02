#pragma once

#include "ICommand.h"
#include "Stereo.h"
#include <memory>

class StereoOnWithCDCommand : public ICommand
{
public:

	StereoOnWithCDCommand(std::shared_ptr<Stereo> stereo)
	{
		_stereo = stereo;
	}

	void execute() override
	{
		_stereo.get()->on();
		_stereo.get()->setCd();
		_stereo.get()->setVolume(11);
	}

	void undo() override
	{
		_stereo.get()->setVolume(0);
		_stereo.get()->off();
	}

private:
	std::shared_ptr<Stereo> _stereo;
};