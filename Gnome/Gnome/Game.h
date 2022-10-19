#pragma once

#include "Hero.h"
#include "Player.h"
#include "Constants.h"

using namespace std;
using namespace constants;

class Game
{
private:
	bool gameOver;
	Player player;
	Player enemy;

	void initPlayer();
	void initPlayerHero();
	void initEnemy();

	void profile();
	void shop();
	void settings();
	void exit();

	inline void printGameWin();
	inline void printGameLose();

	inline void printGameLogo();
	inline void printGameBattle();
	inline void printGameShop();
	inline void printGameSettings();

public:
	Game();
	~Game();

	Player getPlayer();
	void setPlayer(Player player);

	Player getEnemy();
	void setEnemy(Player enemy);

	void initGame();
	void menu();
	
	void printBattle(bool showLogo);
	void battle();
	void attack();

	void printTwoHero(Hero hero1, Hero hero2);
};

