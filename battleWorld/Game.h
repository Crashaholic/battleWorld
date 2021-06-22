#pragma once

#include <windows.h>
#include "Combat.h"
#include "Debug.h"

namespace bwld
{
	/*
		Game is completely valid to be a class
		because of singletons
	*/
	class Game
	{
	public:
		static Game& GetInstance()
		{
			static Game game;
			return game;
		}

		~Game() = default;

	private:
		Game();
		
	};
}
