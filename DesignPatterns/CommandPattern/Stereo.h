#pragma once

class Stereo
{
public:

	virtual void on() = 0;
	virtual void off() = 0;
	virtual void setCd() = 0;
	virtual void setDvd() = 0;
	virtual void setRadio() = 0;
	virtual void setVolume(int) = 0;
};