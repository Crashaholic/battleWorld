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

bool winCondition = false;
bool combatEnded = false;

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

/**
Checks win condition.
*/
void getWinCondition()
{
	if (enemy.getHp() <= 0)
	{
		std::cout << "YOU WON!" << std::endl;
		player.setXp(player.getXp() + enemy.getXp());
		std::cout << "Earned " << enemy.getXp() << "XP" << std::endl;
		winCondition = true;
		combatEnded = true;
		return;
	}
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



	/*===================\
	|	PLAYER'S TURN    |
	\===================*/

	if (sInput == cmdatk)
	{
		getMoveIndex(1);
		getWinCondition();
	}
	else if (sInput == cmdmove1)
	{
		getMoveIndex(2);
		getWinCondition();
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