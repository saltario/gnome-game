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
	bool whoAttack = 1;
	Player player;
	Player enemy;

	void newGame();
	void loadGame();

	void initPlayer();
	void initPlayerHero();

	void profile();
	void shop();
	void settings();
	void exit();

	void battle();
	void enemyStep(bool attack, bool healing);
	void playerStep(bool attack, bool healing);

	void choiceEnemy();
	void endBattle();
	void exitBattle();
	void printBattle(
		bool showLogo,
		bool isHeroAttack, bool isEnemyAttack,
		bool isHeroHealing, bool isEnemyHealing);

	void printPlayer();
	void printName();
	void printDamage();
	void printHealth(
		bool isHeroAttack, bool isEnemyAttack,
		bool isHeroHealing, bool isEnemyHealing);

	void gameWin();
	void gameLose();

	inline void printGameWin();
	inline void printGameLose();

	inline void printGameLogo();
	inline void printGameBattle();
	inline void printGameShop();
	inline void printGameSettings();
	inline void printGameProfile();

	inline void printMenuSeparator();

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

