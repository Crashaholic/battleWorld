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
	player.setAc(rand() % range);
	player.setAr(rand() % range);
	player.setAt(rand() % range);
	player.setDe(rand() % range);
	player.setHp(rand() % range);
	player.setIn(rand() % range);
	player.setMa(rand() % range);
	player.setSp(rand() % range);
	player.setSt(rand() % range);

}


