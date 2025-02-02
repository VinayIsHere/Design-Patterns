#pragma once

#include "Stereo.h"
#include <iostream>

class VideoconPlayerStereo : public Stereo
{
	void on() override
	{
		std::cout << "VideoconPlayerStereo is ON" << std::endl;
	}
	
	void off() override
	{
		std::cout << "VideoconPlayerStereo is OFF" << std::endl;
	}
	
	void setCd() override
	{
		std::cout << "VideoconPlayerStereo is set with a CD" << std::endl;
	}
	
	void setDvd() override
	{
		std::cout << "VideoconPlayerStereo is set with a DVD" << std::endl;
	}	
	
	void setRadio() override
	{
		std::cout << "VideoconPlayerStereo radio is ON" << std::endl;
	}
	
	void setVolume(int volume) override
	{
		std::cout << "VideoconPlayerStereo setting the volume:"<< volume << std::endl;
	}
};