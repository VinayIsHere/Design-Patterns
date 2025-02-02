#pragma once

#include "ICommand.h"
#include "Light.h"
#include <memory>

class LightOffCommand : public ICommand
{

public:

	LightOffCommand(std::shared_ptr<Light> light)
	{
		_light = light;
	}

	void execute() override
	{
		_light.get()->off();
	}

	void undo() override
	{
		_light.get()->on();
	}

private:
	std::shared_ptr<Light> _light;
};