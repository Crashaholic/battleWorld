#pragma once
#include <iostream>
#include <string>
#include "Combat.h"

using std::cout;
using std::endl;

/**
Damage.
*/
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
			return (int)(flatDamage * (1.0 - (rand() % 1500 * 0.0001)));
		}
		else {
			return (int)(flatDamage * (1.0 + (rand() % 1500 * 0.0001)));
		}
	}
}

void mpChecker()
{

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
		damageTemp = damage(player.getAt() * 10, enemy.getAr());
		enemy.setHp(enemy.getHp() - damageTemp);
		std::cout << "Enemy took " << damageTemp << " damage!" << std::endl;
		cout << "wow nice buff" << endl;
		break;

	default:
		cout << "If you're seeing this how the hell did you get an invalid move.";
		break;
	}
}