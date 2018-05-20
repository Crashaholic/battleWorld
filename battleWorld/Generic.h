#pragma once
#include <iostream>
#include <string>
#include <windows.h>

using std::string;
using std::cout;
using std::endl;

void text(string TEXT, int speed)
{
	for (unsigned int i = 0; i <= TEXT.length(); i++)
	{
		cout << TEXT[i];
		Sleep(speed);
	}
}

void newLine()
{
	cout << endl;
}

void clear()
{
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
		<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
		<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
		<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
		<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}