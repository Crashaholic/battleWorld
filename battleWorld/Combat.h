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

	// PLAYER'S TURN
/*
	while (true) 
	{*/
	if (sInput == cmdatk)
	{
		enemy.setHp(enemy.getHp() - (((player.getAt() - enemy.getAr()) > 0) ? (player.getAt() - enemy.getAr()) : 1));
		std::cout << "Enemy took " << ((player.getAt() - enemy.getAr()) >= 0 ? (player.getAt() - enemy.getAr()) : enemy.getHp()) << " damage!" << std::endl;
		std::cout << "[DEBUG] Enemy at " << enemy.getHp() << std::endl;
		if (enemy.getHp() <= 0)
		{
			std::cout << "You Win!" << std::endl;
			winCondition = true;
			combatEnded = true;
		}
	}
	else if (sInput == cmdstat)
	{
		stats();
		return;
	}
	else if (sInput == cmdquit)
	{
		exit(0);
	}
	else
	{
		std::cout << "Wrong input" << std::endl;
	}
	//}
	//ENEMY'S TURN

	Sleep(500);

	if (player.getHp() <= 0)
	{
		std::cout << "You suck at the game" << std::endl;
		winCondition = false;
		combatEnded = true;
	}
	else
	{
		player.setHp(player.getHp() - (enemy.getAt() - player.getAr()));
		std::cout << "Player took " << (enemy.getAt() - player.getAr()) << " damage!" << std::endl;
	}
}
