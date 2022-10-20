#pragma once

#include "Hero.h"
#include "Player.h"
#include "Constants.h"

#include <ctime>

using namespace std;
using namespace constants;

class Game
{
private:
	bool gameOver;
	Player player;
	Player enemy;

	void newGame();
	void loadGame();

	void initPlayer();
	void initPlayerHero();
	void initEnemy();

	void profile();
	void shop();
	void settings();
	void exit();

	void battle();
	void attack();
	void choiceEnemy();
	void endBattle();
	void printBattle(bool showLogo, bool nextEnemy, bool isAttack);

	inline void printGameWin();
	inline void printGameLose();

	inline void printGameLogo();
	inline void printGameBattle();
	inline void printGameShop();
	inline void printGameSettings();
	inline void printGameProfile();

public:
	Game();
	~Game();

	Player getPlayer();
	void setPlayer(Player player);

	Player getEnemy();
	void setEnemy(Player enemy);

	void startMenu();
	void menu();

	void printTwoHero(Hero hero1, Hero hero2);
};

