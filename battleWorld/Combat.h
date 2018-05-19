#pragma once
#include <iostream>
#include <windows.h>
#include "Player.h"
#include "Enemy.h"
#include "EnemyDB.h"
#include <ctime>
#include <stdlib.h>

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

int damage(int attack, int opponentArmor) {
	int flatDamage = (attack - (opponentArmor / 2)) ? (attack - (opponentArmor / 2)) : (2);

	if (flatDamage <= 2) {
		if (flatDamage < 1) {
			return 1;
		}
		else {
			return flatDamage;
		}
	}
	else {
		srand(time(NULL));
		if (rand() % 2 == 1) {
			return flatDamage * (1.0 - (rand() % 1500 * 0.0001));
		}
		else {
			return flatDamage * (1.0 + (rand() % 1500 * 0.0001));
		}
	}
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
		int damageTemp = damage(player.getAt(), enemy.getAr());
		std::cout << "Enemy took " << damageTemp << " damage!" << std::endl;
		enemy.setHp(enemy.getHp() - damageTemp);

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