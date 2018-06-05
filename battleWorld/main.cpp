#include "main.h"

#define TEXT_SPEED 20

using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::cin;
/**
Main.cpp.
*/
int main()
{
	string sName;
	string sInput;

	clear();
	std::cout << "VER INDEV 1.0" << endl << "EXPECT BUGS" << "\n\n\n\n\n\n\n";
	text("Recall your name...", TEXT_SPEED); newLine();
	cout << ">";
	getline(std::cin, sName);

	if (sName == "") 
	{
		text("I can't hear your thoughts, try again.", TEXT_SPEED); newLine();
	}
	text( "An unfortunate event happened on you, " , TEXT_SPEED);
	text(sName, TEXT_SPEED); newLine();
	GetEnemyIndex(6); //1: crab 2: spider
	debug.randStats(100);
	int winCount = 0;
	for (; winCount < 3;)
	{
		if (player.getLv() == 0) player.setLv(1);
		if (combatEnded == false)
		{
			//cout << "Enemy  | " << enemy.getHp() << "HP | " << enemy.getMa() << "MA | "  << enemy.getAt() << "AT | " << endl;
			text("Enemy  | " , TEXT_SPEED - 10);
			text(std::to_string(enemy.getHp()), TEXT_SPEED - 10);
			text(" HP | ", TEXT_SPEED - 10);
			text(std::to_string(enemy.getMa()), TEXT_SPEED - 10);
			text("/", TEXT_SPEED - 10);
			text(std::to_string(enemy.getMaxMa()), TEXT_SPEED - 10);
			text(" MA | ", TEXT_SPEED - 10);
			text(std::to_string(enemy.getAt()), TEXT_SPEED - 10);
			text(" AT | ", TEXT_SPEED - 10);
			newLine();

			//cout << "Player | " << player.getHp() << "HP | "  << player.getMa() << "MA | " << player.getAt()<< "AT | " << endl;
			text(sName , TEXT_SPEED - 10);
			text(" | ", TEXT_SPEED - 10);
			text(std::to_string(player.getHp()), TEXT_SPEED - 10);
			text("/", TEXT_SPEED - 10);
			text(std::to_string(player.getMaxHp()), TEXT_SPEED - 10);
			text(" HP | ", TEXT_SPEED - 10);
			text(std::to_string(player.getMa()), TEXT_SPEED - 10);
			text("/", TEXT_SPEED - 10);
			text(std::to_string(player.getMaxMa()), TEXT_SPEED - 10);
			text(" MA | ", TEXT_SPEED - 10);
			text(std::to_string(player.getAt()), TEXT_SPEED - 10);
			text(" AT | ", TEXT_SPEED - 10);
			newLine();
			cout << ">";

			getline(cin , sInput);
			parseCombat(sInput);
		}
		else
		{
			if (winCondition)
			{
				if (winCount < 2)
				{
					winCount++;
					combatEnded = false;
					winCondition = false;
					GetEnemyIndex(1);
					continue;
				}
				text("And so... The chosen one has indeed been able to overcome his challenges and fight his inner demons.", TEXT_SPEED);
				Sleep(5000);
				break;
			}
			else
			{
				text("And so... The chosen one has subcumbed to the inner demons and no longer walk amongst men, only monsters.", TEXT_SPEED);
				Sleep(5000);
				break;
			}
		}
	}
	return 0;
}
