#pragma once

#include "Hero.h"
#include "Player.h"
#include "Constants.h"

using namespace std;
using namespace constants;

class Game
{
private:
	Player player;
	Player enemy;

	void initEnemy();
	void initPlayerHero();
	void initPlayer();

public:

	Game();
	~Game();

	Player getPlayer();
	void setPlayer(Player player);

	Player getEnemy();
	void setEnemy(Player enemy);

	void startGame();
	void menu();
	void shop();
	void settings();
	void exit();

	void initGame();
	void printBattle();
	void printTwoHero(Hero hero1, Hero hero2);

	void printBattleLogo();
	void printGameLogo();
	void printShopLogo();
	void printSettingsLogo();
};

