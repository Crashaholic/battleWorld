#pragma once
#include "Player.h"
#include "Combat.h"
#include <ctime>
#include <stdlib.h>

namespace bwld
{
	class Debug
	{
	public:
		void RandStats(Player& player, int range)
		{
			//Distribute 24 stat points across STR, DEX, INT, LUK
			Reroll(player);

			//Determine derived stats
			player.health = (20.f + 2.f * player.strength);
			player.maxHealth = (20.f + 2.f * player.strength);
			player.attack = (player.strength + 1);
			player.speed = (player.dexterity + 1);
			player.maxMagic = (player.intelligence + 1);
			player.magic = (player.maxMagic);
			player.accuracy = (player.dexterity + (int)(player.luck * 0.333333) + 1);

			/*
			player.setAc(rand() % range);
			player.setAr(rand() % range);
			player.setAt(rand() % range);
			player.dexterity = rand() % range);
			player.setHp(rand() % range);
			player.intelligence = rand() % range);
			player.setMa(rand() % range);
			player.setSp(rand() % range);
			player.strength = rand() % range);
			*/

		}

	} debug;
}

