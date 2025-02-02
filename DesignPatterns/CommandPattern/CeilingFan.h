#pragma once

#define HIGH 3
#define MEDIUM 2
#define LOW 1
#define OFF 0

#include <iostream>

class CeilingFan
{

public:

	virtual void on() = 0;
	virtual void fanOff() = 0;

	void high()
	{
		_speed = HIGH;
		std::cout << "*** FAN IS HIGH ***"<< std::endl;
	}

	void medium()
	{
		_speed = MEDIUM;
		std::cout << "*** FAN IS MEDIUM ***"<< std::endl;
	}

	void low()
	{
		_speed = LOW;
		std::cout << "*** FAN IS LOW ***"<< std::endl;
	}

	void off()
	{
		_speed = OFF;
		std::cout << "*** FAN IS OFF ***"<< std::endl;
	}

	int getSpeed()
	{
		return _speed;
	}

private:
	int _speed;
};