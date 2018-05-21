#pragma once
#include <iostream>
#include <string>
#include <windows.h>

using std::string;
using std::cout;
using std::endl;

/**
Outputs one char by one from the TEXT based on speed.
*/
void text(string TEXT, int speed)
{
	for (unsigned int i = 0; i <= TEXT.length(); i++)
	{
		cout << TEXT[i];
		Sleep(speed);
	}
}

/**
Creates a new line.
*/
void newLine()
{
	cout << endl;
}

//TODO
/**
Puts the stats to the top #TODO
*/
void toTop()
{

}

/**
Clears the screen.
*/
void clear()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}