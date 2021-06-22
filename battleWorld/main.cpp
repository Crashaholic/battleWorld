#include "Game.h"

using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::cin;
/**
Main.cpp.
*/

using namespace bwld;

using std::to_string;

int main()
{
	string sName;
	string sInput;

	Player player = Player();
	Enemy enemy = Enemy();

	con::clear();
	std::cout << "VER INDEV 1.0" << endl << "EXPECT BUGS" << "\n\n\n\n\n\n\n";
	Sleep(1000);
	con::text("Recall your name...\n");
	cout << ">";
	getline(std::cin, sName);

	if (sName == "") 
	{
		con::text("I can't hear your thoughts, try again.\n");
	}
	con::text( "An unfortunate event happened on you, ");
	con::text(sName + '\n');
	GetEnemyIndex(enemy, 6); //1: crab 2: spider
	debug.RandStats(player, 100);
	int winCount = 0;
	for (; winCount < 3;)
	{
		if (player.level == 0)
			player.level = 1;
		if (combatEnded == false)
		{
			con::text(enemy.GetShownStats());
			con::text(player.GetShownStats());

			cout << ">";

			getline(cin , sInput);
			parseCombat(player, enemy, sInput);
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
					GetEnemyIndex(enemy, 1);
					continue;
				}
				con::text("And so... The chosen one has indeed been able to overcome his challenges and fight his inner demons.", DEFAULT_TEXT_SPEED);
				Sleep(5000);
			}
			else
			{
				con::text("And so... The chosen one has subcumbed to the inner demons and no longer walk amongst men, only monsters.", DEFAULT_TEXT_SPEED);
				Sleep(5000);
			}
			break;
		}
	}
	return 0;
}
