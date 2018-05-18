#include <iostream>
#include <string>
#include <windows.h>
#include "Player.h"
#include "Enemy.h"
#include "EnemyDB.h"
#include "Debug.h"
#include "Combat.h"

using std::string;

int main()
{
	string sName;
	string sInput;

	int temp;

	bool battleSuccess;
	bool battleEngage;

	std::cout << "Recall your name..." << std::endl << ">";
	std::getline(std::cin, sName);

	if (sName == "") std::cout << "I can't hear your thoughts, try again." << std::endl;

	std::cout << "And so, " << sName <<  ", your adventure begins." << std::endl
		<< "You wake up in a white void, full of enemies" << std::endl
		<< "What will you do?" << std::endl;
	std::cout << "\n";
	std::cout << "\n";
	GetEnemyIndex(1); //1: crab 2: spider
	debug.randStats(20);

	while (true) 
	{
		if (player.getLv() == 0) player.setLv(1);
		if (combatEnded == false) 
		{
			std::cout << ">";
			std::getline(std::cin , sInput);
			parseCombat(sInput);
		}
		else
		{
			if (winCondition)
			{
				std::cout << "And so... The chosen one has indeed been able to overcome his challenges and fight his inner demons.";
				Sleep(5000);
			}
			else
			{
				std::cout << "And so... The chosen one has subcumbed to the inner demons and no longer walk amongst men, only monsters.";
				Sleep(5000);
			}
			break;
		}
	}
	return 0;
}
