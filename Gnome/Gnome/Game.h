#pragma once

#include "Hero.h"
#include "Player.h"
#include "Constants.h"

using namespace std;
using namespace constants;

class Game
{
public:
	Game();
	~Game();

	void printBattle(Player player, Hero playerHero, Player enemy, Hero enemyHero);
};

