#pragma once
#include "Entity.h"
#include "Generic.h"
#include "string"

namespace bwld
{
	struct Player : public Entity
	{
	public:
		void Checklvl()
		{
			int nextlvl = level + 1;
			/*if (player.getXp() == exp(1.2 * nextlvl))*/
			if (xp >= 2 * nextlvl)
			{
				level++;
				con::text("Leveled Up! ", 10);
				Sleep(400);
				con::text("\n\n\t\t!!!Your character is now Level ");
				con::text(level);
				con::text("!!!\n\n");
				Sleep(400);
			}
		}
			
	};
}