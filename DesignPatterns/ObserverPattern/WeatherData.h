#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include "ISubject.h"

class WeatherData : public ISubject
{
public:

	WeatherData() = default;

	void registerObserver(std::shared_ptr<IObserver> observer) override {
		_observers.push_back(observer);
	}

	void removeObserver(std::shared_ptr<IObserver> observer) override {
		_observers.erase(
			std::remove_if(_observers.begin(), _observers.end(),
				[&observer](const std::shared_ptr<IObserver>& o) {
								return o.get() == observer.get();
							}),
			_observers.end());
	}

	void notifyObservers() override {
		for (const auto& observer : _observers) {
			if (observer) {
				observer->update(temperature, humidity, pressure);
			}
		}
	}

	void measurementsChanged()
	{
		notifyObservers();
	}

	void setMeasurements(float temperature, float humidity, float pressure)
	{
		this->temperature = temperature;
		this->humidity = humidity;
		this->pressure = pressure;

		measurementsChanged();
	}

	~WeatherData() = default;

private:

	float temperature;
	float humidity;
	float pressure;

	std::vector<std::shared_ptr<IObserver>> _observers;
};