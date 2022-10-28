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
private:
	Player player;
	Player enemy;

	bool gameOver;
	bool whoAttack = 1;
	
	void newGame();
	void loadGame();

	void initPlayer();
	void initPlayerHero();

	void profile();
	void shop();
	void settings();
	void exit();

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

	void enemyStep(bool attack = false, bool healing = false);
	void playerStep(bool attack = false, bool healing = false);

	void gameWin();
	void gameLose();

	inline void printGameWin();
	inline void printGameLose();

	void choiceEnemy();
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

public:
	Game();
	~Game();

	Player getPlayer();
	void setPlayer(Player player);

	Player getEnemy();
	void setEnemy(Player enemy);

	void startMenu();
	void menu();

};

