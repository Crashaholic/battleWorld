#include "main.h"

#define TEXT_SPEED 20

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

	clear();

	text("Recall your name...", TEXT_SPEED); newLine();
	cout << ">";
	getline(std::cin, sName);

	if (sName == "") 
	{
		text("I can't hear your thoughts, try again.", TEXT_SPEED); newLine();
	}
	text( "An unfortunate event happened on you," , TEXT_SPEED);
	text(sName, TEXT_SPEED); newLine();
	GetEnemyIndex(6); //1: crab 2: spider

	clear();

	debug.randStats(100);

	while (true) 
	{
		if (player.getLv() == 0) player.setLv(1);
		if (combatEnded == false)
		{
			//cout << "Enemy  | " << enemy.getHp() << "HP | " << enemy.getMa() << "MA | "  << enemy.getAt() << "AT | " << endl;
			text("Enemy  | " , TEXT_SPEED - 10);
			text(std::to_string(enemy.getHp()), TEXT_SPEED - 10);
			text("HP | ", TEXT_SPEED - 10);
			text(std::to_string(enemy.getMa()), TEXT_SPEED - 10);
			text("MA | ", TEXT_SPEED - 10);
			text(std::to_string(enemy.getAt()), TEXT_SPEED - 10);
			text("AT | ", TEXT_SPEED - 10);
			newLine();

			//cout << "Player | " << player.getHp() << "HP | "  << player.getMa() << "MA | " << player.getAt()<< "AT | " << endl;
			text("Player  | " , TEXT_SPEED - 10);
			text(std::to_string(player.getHp()), TEXT_SPEED - 10);
			text("HP | ", TEXT_SPEED - 10);
			text(std::to_string(player.getMa()), TEXT_SPEED - 10);
			text("MA | ", TEXT_SPEED - 10);
			text(std::to_string(player.getAt()), TEXT_SPEED - 10);
			text("AT | ", TEXT_SPEED - 10);
			newLine();
			cout << ">";

			getline(cin , sInput);
			parseCombat(sInput);
		}
		else
		{
			if (winCondition)
			{
				text("And so... The chosen one has indeed been able to overcome his challenges and fight his inner demons.", TEXT_SPEED);
				Sleep(5000);
			}
			else
			{
				text("And so... The chosen one has subcumbed to the inner demons and no longer walk amongst men, only monsters.", TEXT_SPEED);
				Sleep(5000);
			}
			break;
		}
	}
	return 0;
}
