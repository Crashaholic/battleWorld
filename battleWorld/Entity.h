#pragma once

#include <string>
#include "Generic.h"

namespace bwld
{
	struct Entity
	{
		std::string name;

		int level;
		unsigned int xp;

		int armour;

		int strength;
		float health;
		float maxHealth;
		int attack;

		int intelligence;
		int magic;
		int maxMagic;

		int dexterity;
		int speed;
		int luck;
		int accuracy;

		std::string GetShownStats() const
		{

			/*
			con::text(sName , DEFAULT_TEXT_SPEED - 10);
			con::text(" | ", DEFAULT_TEXT_SPEED - 10);
			con::text(to_string(player.health), DEFAULT_TEXT_SPEED - 10);
			con::text("/", DEFAULT_TEXT_SPEED - 10);
			con::text(to_string(player.maxHealth), DEFAULT_TEXT_SPEED - 10);
			con::text(" HP | ", DEFAULT_TEXT_SPEED - 10);
			con::text(to_string(player.magic), DEFAULT_TEXT_SPEED - 10);
			con::text("/", DEFAULT_TEXT_SPEED - 10);
			con::text(to_string(player.maxMagic), DEFAULT_TEXT_SPEED - 10);
			con::text(" MA | ", DEFAULT_TEXT_SPEED - 10);
			con::text(to_string(player.attack), DEFAULT_TEXT_SPEED - 10);
			con::text(" AT | ", DEFAULT_TEXT_SPEED - 10);
			con::text("\n");
			*/
			std::string temp;
			temp += name + " | " + std::to_string(health) + "/" + std::to_string(maxHealth) + " HP | " +
				std::to_string(magic) + "/" + std::to_string(maxMagic) + " MA | " +
				std::to_string(attack) + " AT |\n";
			return temp;
		}

	};
}
