#pragma once
#include <iostream>
#include <string>
#include "Combat.h"

using std::cout;
using std::endl;

namespace bwld
{
	/**
	Returns int.
	Calculates damage, returns damage amount, but does not set health.
	*/
	int Damage(int attack, int opponentArmor)
	{
		int flatDamage;

		if (attack <= 2) 
		{
			flatDamage = (attack - (opponentArmor / 2) > 2) ? (attack - (opponentArmor / 2)) : (2);
			if (flatDamage < 2) 
			{
				return 1;
			}
			else 
			{
				return flatDamage;
			}
		}
		else 
		{
			srand(time(NULL));
			if (rand() % 2 == 1) 
			{
				flatDamage = (int)round((attack * (1.0 - (rand() % 1500 * 0.0001)))) - (opponentArmor / 2);
				if (flatDamage < 2) 
				{
					return 1;
				}
				else 
				{
					return flatDamage;
				}
			}
			else 
			{
				flatDamage = (int)round((attack * (1.0 + (rand() % 1500 * 0.0001)))) - (opponentArmor / 2);
				if (flatDamage < 2) 
				{
					return 1;
				}
				else 
				{
					return flatDamage;
				}
			}
		}
	}

	/**

	Checks for the player MP sufficiency
	*/
	bool mpChecker(Player player, int req)
	{
		if (player.magic >= req) return true;
		else return false;
	}

	/**

	Get a move by index.
	*/
	void getMoveIndex(Player& player, Enemy& enemy, int index)
	{
		int damageTemp;// = damage(player.attack, enemy.armour);

		/* ___________________________
		* | index | Name              |
		* | 1     | Normal Attack     |
		* | 2     | Strong Attack     |
		* | 3     | Heal              |
		* |
		*/

		switch (index)
		{
		case 1: //NORMAL ATTACK
		{
			damageTemp = Damage(player.attack, enemy.armour);
			std::cout << "Enemy took " << damageTemp << " damage!" << std::endl;
			enemy.health = (enemy.health - damageTemp);
			break;
		}
		case 2: // STRONG
			if (mpChecker(player, 1))
			{
				player.magic = (player.magic - 1);
				damageTemp = Damage(player.attack * 10, enemy.armour);
				enemy.health = (enemy.health - damageTemp);
				std::cout << "Enemy took " << damageTemp << " damage!" << std::endl;
				//cout << "wow nice buff" << endl;
			}
			else
			{
				std::cout << "Not enough magic." << std::endl;
			}
			break;
		case 3: // HEAL
			if (mpChecker(player, 1))
			{
				player.magic = (player.magic - 1);
				int healAmt = Damage(player.health, player.intelligence);
				player.health = (player.health + healAmt);
				con::text("Player healed for ");
				con::text(healAmt);
				con::text(" amount.\n");
			}
			else
			{
				std::cout << "Not enough magic." << std::endl;
			}
			break;
		default:
			cout << "If you're seeing this how the hell did you get an invalid move." << endl;
			break;
		}
	}
}