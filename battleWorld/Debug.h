#pragma once
#include "Player.h"
#include "Combat.h"
#include <ctime>
#include <stdlib.h>

class Debug
{
public:
	void randStats(int range);
} debug;


void Debug::randStats(int range)
{
	srand(time(NULL));
	player.setXp(0);
	player.setAc(0);
	player.setAr(4);
	player.setAt(0);
	player.setDe(0);
	player.setHp(0);
	player.setIn(0);
	player.setMa(0);
	player.setSp(0);
	player.setSt(0);
	player.setLk(0);

	//Distribute 24 stat points across STR, DEX, INT, LUK
	reroll();

	//Determine derived stats
	player.setHp(20 + 2 * player.getSt());
	player.setAt(player.getSt() + 1);
	player.setSp(player.getDe() + 1);
	player.setMa(player.getIn() + 1);
	player.setAc(player.getDe() + (int) (player.getLk() * 0.333333) + 1);

	/*
	player.setAc(rand() % range);
	player.setAr(rand() % range);
	player.setAt(rand() % range);
	player.setDe(rand() % range);
	player.setHp(rand() % range);
	player.setIn(rand() % range);
	player.setMa(rand() % range);
	player.setSp(rand() % range);
	player.setSt(rand() % range);
	*/

}


