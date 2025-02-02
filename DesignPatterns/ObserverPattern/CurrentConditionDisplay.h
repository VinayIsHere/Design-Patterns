#pragma once

#include "IObserver.h"
#include "IDisplayElement.h"
#include "WeatherData.h"
#include <iostream>
#include <memory>

class CurrentConditionDisplay: public IObserver, public IDisaplyElement
{

public:

	CurrentConditionDisplay(std::shared_ptr<WeatherData> weatherData): temperature(0), humidity(0) {
		this->weatherData = weatherData;
	}

	void update(float temp, float humidity, float pressure) override {
		this->temperature = temp;
		this->humidity = humidity;
		display();
	}

	void display() override {
		std::cout << "Current conditions: temperature:" << temperature << ", humidity:" << humidity<<std::endl;
	}

private:

	float temperature;
	float humidity;
	std::shared_ptr<WeatherData> weatherData;
};