#pragma once

#include <ctime>
#include <cmath>

#include "Hero.h"
#include "Player.h"

#include "Functions.h"
#include "Constants.h"
#include "Colors.h"

using namespace std;
using namespace constants;
using namespace colors;

class Game
{
public:
	Game();
	~Game();

	void start();

private:
	Player player;
	Player enemy;

	Player getPlayer();
	void setPlayer(Player player);

	Player getEnemy();
	void setEnemy(Player enemy);

	bool battleOver;
	bool whoAttack = 1;
	
	void startScreen();
	void menuScreen();

	void newGame();
	void loadGame();

	void aboutScreen();
	void shopScreen();
	void settingsScreen();
	void gameExit();

	void printTwoHero(int heroID_1, int heroID_2, int nextLineOfHerosDiv = 0);
	void printSeparatorForShop(int heroID_1, int heroID_2, int nextLineOfHerosDiv = 0);

	void printShopName(int heroID_1, int heroID_2, int nextLineOfHerosDiv = 0);
	void printShopHealth(int heroID_1, int heroID_2, int nextLineOfHerosDiv = 0);
	void printShopDamage(int heroID_1, int heroID_2, int nextLineOfHerosDiv = 0);
	void printShopPrice(int heroID_1, int heroID_2, int nextLineOfHerosDiv = 0);

	inline void printMenuSeparator();

	void battle();
	void setPlayerHeroAttributes();
	void setEnemyHeroAttributes();
	void printBattle(bool showLogo = true);

	void printPlayer();
	void printName();
	void printDamage();
	void printHealth(
		bool isHeroAttack = false, bool isEnemyAttack = false,
		bool isHeroHealing = false, bool isEnemyHealing = false);

	void enemyStep(int state);
	void playerStep(int state);

	void gameWin();
	void gameLose();
	void gameOver();

	inline void printGameWin();
	inline void printGameLose();

	void choiceEnemy();
	int getEnemyState();
	void endBattle();
	void exitBattle();

	inline void printGameLogo();
	inline void printGameStart();
	inline void printGameBattle();
	inline void printGameShop();
	inline void printGameSettings();
	inline void printGameAbout();
	inline void printGameOver();

	void printEmptySeparator();
	void printSeparatorForBattle();

	void showHelp(string helpText, int postion = consoleHeight, int textColor = helpColor);
	void playerChangeName();
};

