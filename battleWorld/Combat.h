#pragma once
#include <iostream>
#include <windows.h>
#include <ctime>
#include <stdlib.h>
#include "Player.h"
#include "Enemy.h"
#include "EnemyDB.h"
#include "MovesDB.h"
#include "Generic.h"

namespace bwld
{
	bool winCondition = false;
	bool combatEnded = false;

	/**
	Outputs current player stats. stats belong to Player.h
	*/
	void stats(Player& player)
	{
		std::cout
			<< "Strength:     " << player.strength << std::endl
			<< "Dexterity:    " << player.dexterity << std::endl
			<< "Intelligence: " << player.intelligence << std::endl
			<< std::endl
			<< "Health:       " << player.health << std::endl
			<< "Max Health    " << player.maxHealth << std::endl
			<< "Magic:        " << player.magic << std::endl
			<< "Max Magic:    " << player.maxMagic << std::endl
			<< std::endl
			<< "Luck:         " << player.luck << std::endl
			<< "Accuracy:     " << player.accuracy << std::endl
			<< "Armour:       " << player.armour << std::endl
			<< "Attack:       " << player.attack << std::endl
			<< "Speed:        " << player.speed << std::endl;
	}

	/**

	Returns void.
	Rerolls STR, DEX, INT, LUK. Does not recalculate derived stats.
	*/
	void Reroll(Player& player)
	{
		player.strength = 4;
		player.dexterity = 4;
		player.intelligence = 4;
		player.luck = 4;
		if (rand() % 3 == 0) 
		{
			switch (rand() % 4) 
			{
			case 0:
				player.strength = player.strength + 4;
				break;
			case 1:
				player.dexterity = player.dexterity + 4;
				break;
			case 2:
				player.intelligence = player.intelligence + 4;
				break;
			case 3:
				player.luck = player.luck + 4;
				break;
			}

			for (int statpoints = 4; statpoints > 0; statpoints--) {
				switch (rand() % 4) {
				case 0:
					player.strength = player.strength + 1;
					break;
				case 1:
					player.dexterity = player.dexterity + 1;
					break;
				case 2:
					player.intelligence = player.intelligence + 1;
					break;
				case 3:
					player.luck = player.luck + 1;
					break;
				}
			}
		}
		else {
			for (int statPoints = 8; statPoints > 0; statPoints--)
			{
				switch (rand() % 4) {
				case 0:
					player.strength = player.strength + 1;
					break;
				case 1:
					player.dexterity = player.dexterity + 1;
					break;
				case 2:
					player.intelligence = player.intelligence + 1;
					break;
				case 3:
					player.luck = player.luck + 1;
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
			con::text("Changes applied!", 10);
		}
		else if (keyAssign == 'w')
		{
			wMove = moveIndex;
			con::text("Changes applied!", 10);
		}
		else if (keyAssign == 'e')
		{
			eMove = moveIndex;
			con::text("Changes applied!", 10);
		}
		else if (keyAssign == 'r')
		{
			rMove = moveIndex;
			con::text("Changes applied!", 10);
		}
		else if (keyAssign == 't')
		{
			tMove = moveIndex;
			con::text("Changes applied!", 10);
		}
		else
		{
			con::text("[ERROR] EXPECTED 'q', 'w', 'e', 'r' or 't'", 10);
		}
	}

	/**
	Checks win condition.
	*/
	bool getWinCondition(Player& player, Enemy& enemy)
	{
		if (enemy.health <= 0)
		{
			std::cout << "YOU WON!" << std::endl;
			player.xp = (player.xp + enemy.xp);
			std::cout << "Earned " << enemy.xp << "XP" << std::endl;
			//player.checklvl();
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
	void parseCombat(Player& player, Enemy& enemy, std::string sInput)
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
			getMoveIndex(player, enemy, 1);
			if (getWinCondition(player, enemy)) return;
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
			getMoveIndex(player, enemy, qMove);
			if (getWinCondition(player, enemy)) return;
		}
		else if (sInput == cmdmove2) // MOVE W
		{
			getMoveIndex(player, enemy, wMove);
			if (getWinCondition(player, enemy)) return;
		}
		else if (sInput == cmdmove3) // MOVE E
		{
			getMoveIndex(player, enemy, eMove);
			if (getWinCondition(player, enemy)) return;
		}
		else if (sInput == cmdmove4) // MOVE R
		{
			getMoveIndex(player, enemy, rMove);
			if (getWinCondition(player, enemy)) return;
		}
		else if (sInput == cmdmove5) // MOVE T
		{
			getMoveIndex(player, enemy, tMove);
			if (getWinCondition(player, enemy)) return;
		}
		else if (sInput == cmdassign)
		{
			con::text("Enter a key from q ,w, e, r or t: ", 10);
			std::getline(std::cin, overflowPrevent);
			keyChange = overflowPrevent[0];
			con::text("Enter move index id: ", 10);
			std::getline(std::cin, overflowPrevent);
			newMoveIndex = ((int)overflowPrevent[0] - 48);
			assignMove(keyChange, newMoveIndex);
			con::text("\n");
		}
		else if (sInput == cmdstat)
		{
			stats(player);
			return;
		}
		else if (sInput == cmdreroll)
		{
			Reroll(player);
			stats(player);
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

		int damageTemp = Damage(enemy.attack, player.armour);
		std::cout << "Player took " << damageTemp << " damage!" << std::endl;
		player.health = (player.health - damageTemp);
		if (player.health <= 0)
		{
			std::cout << "YOU LOST!" << std::endl;
			winCondition = false;
			combatEnded = true;
		}
	}
}