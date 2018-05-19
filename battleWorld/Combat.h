#pragma once
#include <iostream>
#include <windows.h>
#include "Player.h"
#include "Enemy.h"
#include "EnemyDB.h"

bool winCondition = false;
bool combatEnded = false;

void stats()
{
	std::cout
		<< "Accuracy:     " << player.getAc() << std::endl
		<< "Armour:       " << player.getAr() << std::endl
		<< "Attack:       " << player.getAt() << std::endl
		<< "Dexterity:    " << player.getDe() << std::endl
		<< "Health:       " << player.getHp() << std::endl
		<< "Intelligence: " << player.getIn() << std::endl
		<< "Magic:        " << player.getMa() << std::endl
		<< "Speed:        " << player.getSp() << std::endl
		<< "Strength:     " << player.getSt() << std::endl;
}

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

	/*===================\
	|	PLAYER'S TURN    |
	\===================*/

	if (sInput == cmdatk)
	{
		std::cout << "Enemy took " << ((player.getAt() - enemy.getAr()) >= 0 ? (player.getAt() - enemy.getAr()) : enemy.getHp()) << " damage!" << std::endl;
		enemy.setHp(enemy.getHp() - (((player.getAt() - enemy.getAr()) > 0) ? (player.getAt() - enemy.getAr()) : 1));
		if (enemy.getHp() <= 0)
		{
			std::cout << "YOU WON!" << std::endl;
			winCondition = true;
			combatEnded = true;
			return;
		}
	}
	else if (sInput == cmdstat)
	{
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

	std::cout << "Player took " << ((enemy.getAt() - player.getAr()) > 0 ? (enemy.getAt() - player.getAr()) : player.getHp() % 2 + 1) << " damage!" << std::endl;
	player.setHp((player.getHp() - (((enemy.getAt() - player.getAr()) > 0) ? (enemy.getAt() - player.getAr()) : player.getHp() % 2 + 1)));
	if (player.getHp() <= 0)
	{
		std::cout << "YOU LOST!" << std::endl;
		winCondition = false;
		combatEnded = true;
	}
}
