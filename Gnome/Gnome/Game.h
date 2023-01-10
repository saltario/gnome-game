#pragma once

#include <ctime>

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

	bool gameOver;
	bool whoAttack = 1;
	
	void startScreen();
	void menuScreen();

	void newGame();
	void loadGame();

	void profileScreen();
	void shopScreen();
	void settingsScreen();
	void gameExit();

	void printShopName(int heroID_1, int heroID_2);
	void printShopHealth(int heroID_1, int heroID_2);
	void printShopDamage(int heroID_1, int heroID_2);
	void printShopPrice(int heroID_1, int heroID_2);

	inline void printMenuSeparator();

	void battle();
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
	inline void printGameProfile();

	void printEmptySeparator();
	void printSeparatorForBattle();
	void printSeparatorForShop(int heroID_1, int heroID_2);

	void showHelp(string helpText);
	void printTwoHero(int heroID_1, int heroID_2);
};

