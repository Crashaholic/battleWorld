#include "Combat.h"

/**
Outputs current player stats. stats belong to Player.h
*/
void stats()
{
	std::cout
		<< "Strength:     " << player.getSt() << std::endl
		<< "Dexterity:    " << player.getDe() << std::endl
		<< "Intelligence: " << player.getIn() << std::endl
		<< std::endl
		<< "Health:       " << player.getHp() << std::endl
		<< "Magic:        " << player.getMa() << std::endl
		<< "Max Magic:    " << player.getMaxMa() << std::endl
		<< std::endl
		<< "Luck:         " << player.getLk() << std::endl
		<< "Accuracy:     " << player.getAc() << std::endl
		<< "Armour:       " << player.getAr() << std::endl
		<< "Attack:       " << player.getAt() << std::endl
		<< "Speed:        " << player.getSp() << std::endl;
}

/**

Returns void.
Rerolls STR, DEX, INT, LUK. Does not recalculate derived stats.
*/
void reroll() {
	player.setSt(4);
	player.setDe(4);
	player.setIn(4);
	player.setLk(4);
	if (rand() % 3 == 0) {
		switch (rand() % 4) {
		case 0:
			player.setSt(player.getSt() + 4);
			break;
		case 1:
			player.setDe(player.getDe() + 4);
			break;
		case 2:
			player.setIn(player.getIn() + 4);
			break;
		case 3:
			player.setLk(player.getLk() + 4);
			break;
		}

		for (int statpoints = 4; statpoints > 0; statpoints--) {
			switch (rand() % 4) {
			case 0:
				player.setSt(player.getSt() + 1);
				break;
			case 1:
				player.setDe(player.getDe() + 1);
				break;
			case 2:
				player.setIn(player.getIn() + 1);
				break;
			case 3:
				player.setLk(player.getLk() + 1);
				break;
			}
		}
	}
	else {
		for (int statPoints = 8; statPoints > 0; statPoints--)
		{
			switch (rand() % 4) {
			case 0:
				player.setSt(player.getSt() + 1);
				break;
			case 1:
				player.setDe(player.getDe() + 1);
				break;
			case 2:
				player.setIn(player.getIn() + 1);
				break;
			case 3:
				player.setLk(player.getLk() + 1);
				break;
			}
		}
	}
}

/*
GLOBAL VARIABLES FOR MOVES, TOUCH IF NECESSARY
*/

int qMove = 0; /*Move index for [Q] */
int wMove = 0; /*Move index for [W] */
int eMove = 0; /*Move index for [E] */
int rMove = 0; /*Move index for [R] */
int tMove = 0; /*Move index for [T] */

/**
Assigns a move index to a key(from [Q], [W], [E], [R] or [T])
*/
void assignMove(char keyAssign, int moveIndex)
{
	if (keyAssign == 'q')
	{
		qMove = moveIndex;
		text("Changes applied!", 10);
	}
	else if (keyAssign == 'w')
	{
		wMove = moveIndex;
		text("Changes applied!", 10);
	}
	else if (keyAssign == 'e')
	{
		eMove = moveIndex;
		text("Changes applied!", 10);
	}
	else if (keyAssign == 'r')
	{
		rMove = moveIndex;
		text("Changes applied!", 10);
	}
	else if (keyAssign == 't')
	{
		tMove = moveIndex;
		text("Changes applied!", 10);
	}
	else
	{
		text("[ERROR] EXPECTED 'q', 'w', 'e', 'r' or 't'", 10);
	}
}

/**
Checks win condition.
*/
bool getWinCondition()
{
	if (enemy.getHp() <= 0)
	{
		std::cout << "YOU WON!" << std::endl;
		player.setXp(player.getXp() + enemy.getXp());
		std::cout << "Earned " << enemy.getXp() << "XP" << std::endl;
		player.checklvl();
		winCondition = true;
		combatEnded = true;
		return 1;
	}
	else
		return 0;
}

/**
For combat purposes.
*/
void parseCombat(std::string sInput)
{

	std::string cmdatk = "1";
	std::string cmditem1 = "2";
	std::string cmditem2 = "3";

	std::string cmdmove1 = "q";
	std::string cmdmove2 = "w";
	std::string cmdmove3 = "e";
	std::string cmdmove4 = "r";
	std::string cmdmove5 = "t";

	std::string cmdassign = "assign";
	std::string cmdquit = "qqq";
	std::string cmdstat = "stats";
	std::string cmdreroll = "reroll";

	char keyChange;
	string overflowPrevent;
	int newMoveIndex;

	//AVOIDS ASSIGNING MOTHING TO MOVES
	if (qMove == 0 || wMove == 0 || eMove == 0 || rMove == 0 || tMove == 0)
	{
		qMove = 2;
		wMove = 2;
		eMove = 2;
		rMove = 2;
		tMove = 2;
	}

	/*===================\
	|	PLAYER'S TURN    |
	\===================*/

	if (sInput == cmdatk)
	{
		getMoveIndex(1);
		if (getWinCondition()) return;
	}
	else if (sInput == cmditem1)
	{
		//item stuff happens here
		return; // temporary
	}
	else if (sInput == cmditem2)
	{
		//item stuff happens here
		return; // temporary
	}
	else if (sInput == cmdmove1) // MOVE Q
	{
		getMoveIndex(qMove);
		if (getWinCondition()) return;
	}
	else if (sInput == cmdmove2) // MOVE W
	{
		getMoveIndex(wMove);
		if (getWinCondition()) return;
	}
	else if (sInput == cmdmove3) // MOVE E
	{
		getMoveIndex(eMove);
		if (getWinCondition()) return;
	}
	else if (sInput == cmdmove4) // MOVE R
	{
		getMoveIndex(rMove);
		if (getWinCondition()) return;
	}
	else if (sInput == cmdmove5) // MOVE T
	{
		getMoveIndex(tMove);
		if (getWinCondition()) return;
	}
	else if (sInput == cmdassign)
	{
		text("Enter a key from q ,w, e, r or t: ", 10);
		std::getline(std::cin, overflowPrevent);
		keyChange = overflowPrevent[0];
		text("Enter move index id: ", 10);
		std::getline(std::cin, overflowPrevent);
		newMoveIndex = ((int)overflowPrevent[0] - 48);
		assignMove(keyChange, newMoveIndex);
		newLine();
	}
	else if (sInput == cmdstat)
	{
		stats();
		return;
	}
	else if (sInput == cmdreroll)
	{
		reroll();
		stats();
		return;
	}
	else if (sInput == cmdquit)
		exit(0);
	else
		std::cout << "Wrong input" << std::endl;

	/*===================\
	|	 ENEMY'S TURN    |
	\===================*/

	Sleep(500);


	int damageTemp = damage(enemy.getAt(), player.getAr());
	std::cout << "Player took " << damageTemp << " damage!" << std::endl;
	player.setHp(player.getHp() - damageTemp);
	if (player.getHp() <= 0)
	{
		std::cout << "YOU LOST!" << std::endl;
		winCondition = false;
		combatEnded = true;
	}
}