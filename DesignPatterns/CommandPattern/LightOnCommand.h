#pragma once

#include "ICommand.h"
#include "Light.h"
#include <memory>

class LightOnCommand: public ICommand
{

public:

	LightOnCommand(std::shared_ptr<Light> light) {
		_light = light;
	}

	void execute() override {
		_light.get()->on();
	}

	void undo() override {
		_light.get()->off();
	}

private:
	std::shared_ptr<Light> _light;
};