#pragma once
#include <iostream>
#include <string>
#include <windows.h>

#define DEFAULT_TEXT_SPEED 10

using std::string;

namespace con
{
	/**
	Outputs one char by one from the TEXT based on speed.
	*/
	void text(string TEXT, int speed = DEFAULT_TEXT_SPEED)
	{
		for (unsigned int i = 0; i < TEXT.length(); i++)
		{
			std::cout << TEXT[i];
			Sleep(speed);
		}
	}

	void text(int value, int speed = DEFAULT_TEXT_SPEED)
	{
		text(std::to_string(value), speed);
	}

	/**
	Clears the screen.
	*/
	void clear()
	{
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
}
