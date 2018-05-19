#pragma once
#include "Player.h"
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
	player.setAc(0);
	player.setAr(4);
	player.setAt(0);
	player.setDe(0);
	player.setHp(0);
	player.setIn(0);
	player.setMa(0);
	player.setSp(0);
	player.setSt(0);
	player.setLu(0);

	//Distribute 100 stat points across STR, DEX, INT, LUK
	for (int statPoints = 100; statPoints > 0; statPoints--) {
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
			player.setLu(player.getLu() + 1);
			break;
		}
	}

	//Determine derived stats
	player.setHp(20 + 2 * player.getSt());
	player.setAt(player.getSt() + 1);
	player.setSp(player.getDe() + 1);
	player.setMa(player.getIn() + 1);
	player.setAc(player.getLu() + 1);

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


