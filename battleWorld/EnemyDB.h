#pragma once
#include <iostream>
#include "Enemy.h"

/*
	1:crab
	2:spider
	3:zombie
	4:skelebutt
	5:orc
*/


void GetEnemyIndex(int enemyQueue)
{
	switch (enemyQueue)
	{
	case 1: //crab (index 1)
		enemy.setLv(1);

		enemy.setHp(100);
		enemy.setAr(1);
		enemy.setAt(rand() %20);
		enemy.setSt(1);

		enemy.setIn(0);
		enemy.setMa(0);

		enemy.setDe(1);
		enemy.setAc(1);
		enemy.setSp(1);
		std::cout << "Crab appears!" << std::endl;
		break;
	case 2:
		enemy.setLv(1);

		enemy.setHp(200);
		enemy.setAr(2);
		enemy.setAt(1);
		enemy.setSt(1);

		enemy.setIn(0);
		enemy.setMa(0);

		enemy.setDe(1);
		enemy.setAc(1);
		enemy.setSp(1);
		std::cout << "Spider appears!" << std::endl;
		break;
	default:
		break;
	}
}

