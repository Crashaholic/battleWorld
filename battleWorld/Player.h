#pragma once
#include "Entity.h"
#include "Generic.h"
#include "string"

class Player : public Entity
{
public:
	void checklvl();
} player;

void Player::checklvl()
{
	int nextlvl = player.getLv() + 1;
	/*if (player.getXp() == exp(1.2 * nextlvl))*/
	if (player.getXp() >= 2 * nextlvl)
	{
		player.setLv(player.getLv() + 1);
		text("Leveled Up!", 10);
		Sleep(400);
		text("Your character is now Level" , 10);
		text(std::to_string(player.getLv()) , 10);
	}
}