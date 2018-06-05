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
	//Distribute 24 stat points across STR, DEX, INT, LUK
	reroll();

	//Determine derived stats
	player.setHp(20 + 2 * player.getSt());
	player.setMaxHp(20 + 2 * player.getSt());
	player.setAt(player.getSt() + 1);
	player.setSp(player.getDe() + 1);
	player.setMaxMa(player.getIn() + 1);
	player.forceSetMa(player.getMaxMa());
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


