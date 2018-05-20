#pragma once
#include <iostream>
#include "Enemy.h"

/*
	1:crab
	2:spider
	3:zombie
	4:skelebutt
	5:orc
	6:puffball
*/


void GetEnemyIndex(int enemyQueue)
{
	switch (enemyQueue)
	{
	case 1: //crab (index 1)
		enemy.setLv(1);

		enemy.setHp(100);
		enemy.setAr(1);
		enemy.setAt(10);
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
		enemy.setAr(20);
		enemy.setAt(20);
		enemy.setSt(1);

		enemy.setIn(0);
		enemy.setMa(0);

		enemy.setDe(1);
		enemy.setAc(1);
		enemy.setSp(1);
		std::cout << "Spider appears!" << std::endl;
		break;
	case 3:
		enemy.setLv(1);

		enemy.setHp(300);
		enemy.setAr(30);
		enemy.setAt(30);
		enemy.setSt(1);

		enemy.setIn(0);
		enemy.setMa(0);

		enemy.setDe(1);
		enemy.setAc(1);
		enemy.setSp(1);
		std::cout << "Zombie appears!" << std::endl;
		break;
	case 6: //puffball
		enemy.setLv(1);
		enemy.setXp(3);

		enemy.setHp(12);
		enemy.setAr(0);
		enemy.setAt(3);
		enemy.setSt(1);

		enemy.setDe(0);
		enemy.setSp(1);
		
		enemy.setLk(0);
		enemy.setAc(5);
		std::cout << "Puffball appears!" << std::endl;
	default:
		break;
	}
}

