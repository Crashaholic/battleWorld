#pragma once
#include <iostream>
#include <string>
#include "Combat.h"

using std::cout;
using std::endl;

/**

Returns int.
Calculates damage, returns damage amount, but does not set health.
*/
int damage(int attack, int opponentArmor) {
	int flatDamage;

	if (attack <= 2) {
		flatDamage = (attack - (opponentArmor / 2) > 2) ? (attack - (opponentArmor / 2)) : (2);
		if (flatDamage < 2) {
			return 1;
		}
		else {
			return flatDamage;
		}
	}
	else {
		srand(time(NULL));
		if (rand() % 2 == 1) {
			flatDamage = (int)round((attack * (1.0 - (rand() % 1500 * 0.0001)))) - (opponentArmor / 2);
			if (flatDamage < 2) {
				return 1;
			}
			else {
				return flatDamage;
			}
		}
		else {
			flatDamage = (int)round((attack * (1.0 + (rand() % 1500 * 0.0001)))) - (opponentArmor / 2);
			if (flatDamage < 2) {
				return 1;
			}
			else {
				return flatDamage;
			}
		}
	}
}

bool mpChecker(int req)
{
	if (player.getMa() >= req) return true;
	else return false;
}
/**
Get a move by index.
*/
void getMoveIndex(int index)
{
	int damageTemp;// = damage(player.getAt(), enemy.getAr());
	
	switch (index)
	{
	case 1:
		damageTemp = damage(player.getAt(), enemy.getAr());
		std::cout << "Enemy took " << damageTemp << " damage!" << std::endl;
		enemy.setHp(enemy.getHp() - damageTemp);
		break;
	case 2:
		if (mpChecker(5)) {
			player.setMa(player.getMa() - 5);
			damageTemp = damage(player.getAt() * 10, enemy.getAr());
			enemy.setHp(enemy.getHp() - damageTemp);
			std::cout << "Enemy took " << damageTemp << " damage!" << std::endl;
			cout << "wow nice buff" << endl;
		}
		else {
			std::cout << "Not enough magic." << std::endl;
		}
		break;

	default:
		cout << "If you're seeing this how the hell did you get an invalid move.";
		break;
	}
}