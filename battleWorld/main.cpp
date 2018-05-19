#include <iostream>
#include <string>
#include <windows.h>
#include "Player.h"
#include "Enemy.h"
#include "EnemyDB.h"
#include "Debug.h"
#include "Combat.h"

using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::cin;

int main()
{
	string sName;
	string sInput;

	int temp;

	bool battleSuccess;
	bool battleEngage;

	cout << "Recall your name..." << endl << ">";
	getline(std::cin, sName);

	if (sName == "") cout << "I can't hear your thoughts, try again." << endl;

	cout << "And so, " << sName <<  ", your adventure begins." << endl
		<< "You wake up in a white void, full of enemies" << endl
		<< "What will you do?" << endl;
	cout << "\n";
	cout << "\n";
	GetEnemyIndex(1); //1: crab 2: spider

	cout << "Enter your strength:" << endl << "#: ";
	getline(cin , sInput);
	temp = stoi(sInput);

	debug.randStats(100);

	while (true) 
	{
		if (player.getLv() == 0) player.setLv(1);
		if (combatEnded == false)
		{
			cout << "Enemy  | " << enemy.getHp() << "HP | " << enemy.getMa() << "MA | "  << enemy.getAt() << "AT | " << endl;
			cout << "Player | " << player.getHp() << "HP | "  << player.getMa() << "MA | " << player.getAt()<< "AT | " << endl;
			cout << ">";
			getline(cin , sInput);
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
