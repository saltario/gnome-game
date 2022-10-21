#include "Game.h"

Game::Game() {}
Game::~Game() {}

Player Game::getPlayer() { return player; }
void Game::setPlayer(Player player) { this->player = player; }

Player Game::getEnemy() { return enemy; }
void Game::setEnemy(Player enemy) { this->enemy = enemy; }

////////////////// START //////////////////

void Game::startMenu()
{
	printGameLogo();

	cout.fill(' ');
	showConsoleCursor(false);

	string menuSeparator = "-----------";

	bool isMenu = true;
	bool refreshMenu = true;

	int menuIndex = 0;
	int menuChoice = 0;

	while (isMenu)
	{
		if ((GetAsyncKeyState(VK_UP) & 1) || (GetAsyncKeyState('W') & 1))
		{
			refreshMenu = true;

			// Самый верхний элемент меню
			if (menuIndex == 0) { menuChoice = menuIndex; }
			else { menuIndex -= 1; menuChoice = menuIndex; }
		}

		if ((GetAsyncKeyState(VK_DOWN) & 1) || (GetAsyncKeyState('S') & 1))
		{
			refreshMenu = true;

			// Самый нижний элемент меню
			if (menuIndex == 1) { menuChoice = menuIndex; }
			else { menuIndex += 1; menuChoice = menuIndex; }
		}

		if (GetAsyncKeyState(VK_SPACE) & 1)
		{
			system("cls");
			if (menuChoice == 0) { newGame(); break; }
			if (menuChoice == 1) { loadGame(); break; }
		}

		if (refreshMenu)
		{
			refreshMenu = false;
			system("cls");
			printGameLogo();
			setConsoleColor(purpleTextColor);

			if (menuChoice == 0) { coutCentered("> Старт <"); }
			else { coutCentered("Старт"); }
			coutCentered(menuSeparator);

			if (menuChoice == 1) { coutCentered("> Загрузить <"); }
			else { coutCentered("Загрузить"); }

			showHelp("Нажмите пробел для выбора");
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 1) { exit(); break; }
	}
}

void Game::newGame()
{
	printGameLogo();

	initPlayer();
	initPlayerHero();
	initEnemy();
}

void Game::loadGame()
{
	player.setName("player");
	player.setPlayerHero(1);
	setPlayer(player);

	enemy.setPlayerHero(3);
	enemy.setName("enemy");
	setEnemy(enemy);
}

////////////////// END START //////////////////

////////////////// INIT //////////////////

void Game::initPlayer() {

	showConsoleCursor(true);
	string playerName = "player";
	string separator = "			  ";

	int x, y;

	coutCentered("Введите имя:      ", false);
	x = 39;
	y = cursorY();

	setCursorPosition(y, x);
	cin >> playerName;

	player.setName(playerName);
}

void Game::initPlayerHero() 
{
	Hero tmp1 = Hero();
	tmp1 = tmp1.getHeroById(1);

	Hero tmp2 = Hero();
	tmp2 = tmp2.getHeroById(5);

	Player player = getPlayer();

	printTwoHero(tmp1, tmp2);

	setConsoleColor(redTextColor);
	showConsoleCursor(false);
	coutCentered("Выберите героя");

	while (true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1) & 1) { player.setPlayerHero(1); break; }
		if (GetAsyncKeyState(VK_NUMPAD2) & 1) { player.setPlayerHero(5); break; }
	}

	setPlayer(player);
}

void Game::initEnemy() {

	string enemyName = "enemy";

	Player enemy = getPlayer();

	Hero tmp = getEnemy().getPlayerHero();
	tmp = tmp.getHeroById(3);

	enemy.setPlayerHero(3);
	enemy.setName(enemyName);

	setEnemy(enemy);
}

////////////////// END INIT //////////////////

////////////////// MENU //////////////////

void Game::shop()
{
	printGameShop();

	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 1) { menu(); break; }
	}
}

void Game::profile()
{
	printGameProfile();

	player.printProfile();
	player.getPlayerHero().printHero();

	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 1) { menu(); break; }
	}
}

void Game::settings()
{
	printGameSettings();

	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 1) { menu(); break; }
	}
}

void Game::exit()
{

}

void Game::menu() {

	cout.fill(' ');
	showConsoleCursor(false);

	string menuSeparator = "-----------";

	bool isMenu = true;
	bool refreshMenu = true;

	int menuIndex = 0;
	int menuChoice = 0;

	while (isMenu)
	{
		if ((GetAsyncKeyState(VK_UP) & 1) || (GetAsyncKeyState('W') & 1))
		{
			refreshMenu = true;

			// Самый верхний элемент меню
			if (menuIndex == 0) { menuChoice = menuIndex; }
			else { menuIndex -= 1; menuChoice = menuIndex; }
		}

		if ((GetAsyncKeyState(VK_DOWN) & 1) || (GetAsyncKeyState('S') & 1))
		{
			refreshMenu = true;

			// Самый нижний элемент меню
			if (menuIndex == 4) { menuChoice = menuIndex; }
			else { menuIndex += 1; menuChoice = menuIndex; }
		}

		if (GetAsyncKeyState(VK_SPACE) & 1)
		{
			system("cls");
			if (menuChoice == 0) { battle(); }
			if (menuChoice == 1) { profile(); }
			if (menuChoice == 2) { shop(); }
			if (menuChoice == 3) { settings(); }
			if (menuChoice == 4) { exit(); }
		}

		if (refreshMenu)
		{
			refreshMenu = false;
			system("cls");
			printGameLogo();
			setConsoleColor(purpleTextColor);

			if (menuChoice == 0) { coutCentered("> Старт <"); }
			else { coutCentered("Старт"); }
			coutCentered(menuSeparator);

			if (menuChoice == 1) { coutCentered("> Профиль <"); }
			else { coutCentered("Профиль"); }
			coutCentered(menuSeparator);

			if (menuChoice == 2) { coutCentered("> Магазин <"); }
			else { coutCentered("Магазин"); }
			coutCentered(menuSeparator);

			if (menuChoice == 3) { coutCentered("> Настройки <"); }
			else { coutCentered("Настройки"); }
			coutCentered(menuSeparator);

			if (menuChoice == 4) { coutCentered("> Выход <"); }
			else { coutCentered("Выход"); }
			
			showHelp("Нажмите пробел для выбора");
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 1) { exit(); break; }
	}
}

////////////////// END MENU //////////////////

////////////////// BATTLE //////////////////

void Game::printBattle(bool showLogo, bool isHeroAttack = false, bool isEnemyAttack = false)
{
	string str1;
	string str2 = " |";
	string str3;

	if (showLogo) { setCursorPosition(0, 0); printGameBattle(); }

	printSeparatorForBattle();

	////////////////////////////////
	str1 = "| Игрок: ";

	SetConsoleTextAttribute(hConsole, yellowTextColor);
	cout.fill(' ');

	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << player.getName();

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << enemy.getName();

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| Уровень: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << player.getLevel();

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| Уровень: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << enemy.getLevel();

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| Звезды: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << player.getStars();

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| Звезды: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << enemy.getStars();

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////
	printSeparatorForBattle();

	cout.fill(' ');
	setConsoleColor(lightGreenTextColor);

	////////////////////////////////
	str1 = "| Имя: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << player.getPlayerHero().getName();

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| Имя: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << enemy.getPlayerHero().getName();

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| Здоровье: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(player.getPlayerHero().getHealth());

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	if (isHeroAttack) 
	{
		setConsoleColor(redTextColor);
		str3 = to_string(enemy.getPlayerHero().getHealth()) + " - (" + to_string(player.getPlayerHero().getDamage()) + ")";

		str1 = "| Здоровье: ";
		cout.width(heroTextWidth);
		cout << str1;

		cout.width(heroTextWidth - str2.length());
		cout << str3;

		cout.width(str2.length());
		cout << str2 << endl;

		setConsoleColor(lightGreenTextColor);
	}
	else
	{
		str1 = "| Здоровье: ";
		cout.width(heroTextWidth);
		cout << str1;

		cout.width(heroTextWidth - str2.length());
		cout << to_string(enemy.getPlayerHero().getHealth());

		cout.width(str2.length());
		cout << str2 << endl;
	}

	

	////////////////////////////////

	str1 = "| Урон: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(player.getPlayerHero().getDamage());

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| Урон: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(enemy.getPlayerHero().getDamage());

	cout.width(str2.length());
	cout << str2 << endl;

	printSeparatorForBattle();
}

void Game::battle()
{
	gameOver = false;
	bool nextEnemy = true;

	Hero playerHero = Hero();
	playerHero = player.getPlayerHero();

	Hero enemyHero = Hero();
	enemyHero = enemy.getPlayerHero();

	string menuSeparator = "-----------";

	bool isMenu = true;
	bool refreshMenu = true;

	int menuIndex = 0;
	int menuChoice = 0;

	while (isMenu)
	{
		if ((GetAsyncKeyState(VK_UP) & 1) || (GetAsyncKeyState('W') & 1))
		{
			refreshMenu = true;

			// Самый верхний элемент меню
			if (menuIndex == 0) { menuChoice = menuIndex; }
			else { menuIndex -= 1; menuChoice = menuIndex; }
		}

		if ((GetAsyncKeyState(VK_DOWN) & 1) || (GetAsyncKeyState('S') & 1))
		{
			refreshMenu = true;

			// Самый нижний элемент меню
			if (menuIndex == 2) { menuChoice = menuIndex; }
			else { menuIndex += 1; menuChoice = menuIndex; }
		}

		if (GetAsyncKeyState(VK_SPACE) & 1)
		{
			if ((menuChoice == 0) && (gameOver == false)) { nextEnemy = false; refreshMenu = true; attack(); }
			if ((menuChoice == 1) && (nextEnemy)) {  }
			if ((menuChoice == 2) && (nextEnemy)) { refreshMenu = true; choiceEnemy(); }
		}

		if (gameOver) { refreshMenu = false; endBattle(); }

		if (refreshMenu)
		{
			system("cls");
			printBattle(true);
			refreshMenu = false;
			setConsoleColor(purpleTextColor);

			if (menuChoice == 0) { printBattle(1, 1, 0); setConsoleColor(purpleTextColor); coutCentered("> Атака <"); }
			else { coutCentered("Атака"); }
			coutCentered(menuSeparator);

			if (menuChoice == 1) { coutCentered("> Лечение <"); }
			else { coutCentered("Лечение"); }

			if (nextEnemy) 
			{
				coutCentered(menuSeparator);
				if (menuChoice == 2) { coutCentered("> Следующий <"); }
				else { coutCentered("Следующий"); }
			}

			showHelp("Нажмите пробел для выбора");
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 1) { endBattle(); menu(); break; }
	}
}

void Game::attack()
{
	// 1 - Я атакую
	// 0 - Атакует соперник
	bool whoAttack = 1;

	Hero playerHero = Hero();
	playerHero = player.getPlayerHero();

	Hero enemyHero = Hero();
	enemyHero = enemy.getPlayerHero();

	if (whoAttack == 1) {

		enemyHero.setHealth(enemyHero.getHealth() - playerHero.getDamage());
		enemy.setPlayerHero(enemyHero);

		if (enemyHero.getHealth() <= 0) { printGameWin(); printBattle(false); gameOver = true; }
		else { whoAttack = 0; }

		Sleep(100);

	}
	if (whoAttack == 0) {

		playerHero.setHealth(playerHero.getHealth() - enemyHero.getDamage());
		player.setPlayerHero(playerHero);

		if (playerHero.getHealth() <= 0) { printGameLose(); printBattle(false); gameOver = true; }
		else { printBattle(1, 1, 0); gameOver = false; }
	}
}

void Game::choiceEnemy()
{
	srand(time(0));
	int random = 1 + rand() % 6;
	enemy.setPlayerHero(random);
	setEnemy(enemy);
	printBattle(1, 1);
}

void Game::endBattle()
{
	player.setPlayerHero(player.getHeroId());
	enemy.setPlayerHero(enemy.getHeroId());
}

////////////////// END BATTLE //////////////////

////////////////// PRINT HEAD //////////////////

inline void Game::printGameLogo()
{
	setConsoleColor(redTextColor);

	cout << R"(
	      ________                                  
	     /  _____/   ____    ____    _____    ____  
	    /   \  ___  /    \  /  _ \  /     \ _/ __ \ 
	    \    \_\  \|   |  \(  <_> )|  Y Y  \\  ___/ 
	     \______  /|___|  / \____/ |__|_|  / \___  >
	            \/      \/               \/      \/ 
)" << '\n';
}

inline void Game::printGameBattle()
{
	setConsoleColor(redTextColor);

	cout << R"(
	      __________         __    __  .__          
	      \______   \_____ _/  |__/  |_|  |   ____  
	       |    |  _/\__  \\   __\   __\  | _/ __ \ 
	       |    |   \ / __ \|  |  |  | |  |_\  ___/ 
	       |______  /(____  /__|  |__| |____/\___  >
	              \/      \/                     \/ 
)" << '\n';
}

inline void Game::printGameShop()
{
	setConsoleColor(redTextColor);

	cout << R"(
		     _________.__                   
		    /   _____/|  |__   ____ ______  
		    \_____  \ |  |  \ /  _ \\____ \ 
		    /        \|   Y  (  <_> )  |_> >
		   /_______  /|___|  /\____/|   __/ 
		           \/      \/       |__|    
)" << '\n';
}

inline void Game::printGameSettings()
{
	setConsoleColor(redTextColor);

	cout << R"(
	  _________       __    __  .__                      
	 /   _____/ _____/  |__/  |_|__| ____    ____  ______
	 \_____  \_/ __ \   __\   __\  |/    \  / ___\/  ___/
	 /        \  ___/|  |  |  | |  |   |  \/ /_/  >___ \ 
	/_______  /\___  >__|  |__| |__|___|  /\___  /____  >
	        \/     \/                   \//_____/     \/   
)" << '\n';
}

inline void Game::printGameProfile()
{
	setConsoleColor(redTextColor);
	    
	cout << R"(
	  __________                _____.__.__          
	  \______   \_______  _____/ ____\__|  |   ____  
	  |     ___/\_  __ \/  _ \   __\|  |  | _/ __ \ 
	  |    |     |  | \(  <_> )  |  |  |  |_\  ___/ 
	  |____|     |__|   \____/|__|  |__|____/\___  >
	                                              \/   
)" << '\n';
}

inline void Game::printGameWin()
{
	setConsoleColor(redTextColor);
	system("cls");

	cout << R"(
			 __      __.__      ._.
			/  \    /  \__| ____| |
			\   \/\/   /  |/    \ |
			 \        /|  |   |  \|
			  \__/\  / |__|___|  /_
			       \/          \/\/
)" << '\n';
}

inline void Game::printGameLose()
{
	setConsoleColor(redTextColor);
	system("cls");

	cout << R"(
		.____                      ._.
		|    |    ____  ______ ____| |
		|    |   /  _ \/  ___// __ \ |
		|    |__(  <_> )___ \\  ___/\|
		|_______ \____/____  >\___  >_
		        \/         \/     \/\/
)" << '\n';
}

////////////////// END PRINT HEAD //////////////////

void Game::printTwoHero(Hero hero1, Hero hero2)
{
	printSeparatorForShop();

	string str1;
	string str2 = " |";

	cout.fill(' ');
	SetConsoleTextAttribute(hConsole, lightGreenTextColor);

	////////////////////////////////
	str1 = "| Имя: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << hero1.getName();

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| Имя: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << hero2.getName();

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| Здоровье: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(hero1.getHealth());

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| Здоровье: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(hero2.getHealth());

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| Урон: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(hero1.getDamage());

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| Урон: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(hero2.getDamage());

	cout.width(str2.length());
	cout << str2 << endl;

	printSeparatorForShop();
}
