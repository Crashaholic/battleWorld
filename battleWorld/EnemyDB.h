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

namespace bwld
{
	void GetEnemyIndex(Enemy& enemy, int enemyQueue)
	{
		enemy.name = "_";
		switch (enemyQueue)
		{
		case 1: //crab (index 1)
			enemy.level = 1;

			enemy.health = 100;
			enemy.armour = 1;
			enemy.attack = 10;
			enemy.strength = 1;

			enemy.intelligence = 0;
			enemy.magic = 0;

			enemy.dexterity = 1;
			enemy.accuracy = 1;
			enemy.speed = 1;
			enemy.name = "Crab";
			std::cout << "Crab appears!" << std::endl;
			break;
		case 2:
			enemy.level = 1;

			enemy.health = 200;
			enemy.armour = 20;
			enemy.attack = 20;
			enemy.strength = 1;

			enemy.intelligence = 0;
			enemy.magic = 0;

			enemy.dexterity = 1;
			enemy.accuracy = 1;
			enemy.speed = 1;
			std::cout << "Spider appears!" << std::endl;
			break;
		case 3:
			enemy.level = 1;

			enemy.health = 300;
			enemy.armour = 30;
			enemy.attack = 30;
			enemy.strength = 1;

			enemy.intelligence = 0;
			enemy.magic = 0;

			enemy.dexterity = 1;
			enemy.accuracy = 1;
			enemy.speed = 1;
			std::cout << "Zombie appears!" << std::endl;
			break;
		case 6: //puffball
			enemy.level = 1;
			enemy.xp = 5;

			enemy.health = 12;
			enemy.armour = 0;
			enemy.attack = 3;
			enemy.strength = 1;

			enemy.dexterity = 0;
			enemy.speed = 1;

			enemy.luck = 0;
			enemy.accuracy = 5;
			std::cout << "Puffball appears!" << std::endl;
		default:
			break;
		}
	}
}

