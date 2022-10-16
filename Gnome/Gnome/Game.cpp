#include "Game.h"

Game::Game() {}
Game::~Game() {}

Player Game::getPlayer() { return player; }
void Game::setPlayer(Player player) { this->player = player; }

Player Game::getEnemy() { return enemy; }
void Game::setEnemy(Player enemy) { this->enemy = enemy; }

////////////////// INIT //////////////////

void Game::initGame()
{
	printGameLogo();

	initPlayer();
	initPlayerHero();
	initEnemy();
}

void Game::initPlayer() {

	string playerName = "player";
	string separator = "			  ";

	cout << separator << "Введите имя: ";
	cin >> playerName;
	player.setName(playerName);
}

void Game::initPlayerHero() {

	string separator = "			  ";

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
		if (GetAsyncKeyState(VK_NUMPAD1) & 1) { player.setPlayerHero(tmp1); break; }
		if (GetAsyncKeyState(VK_NUMPAD2) & 1) { player.setPlayerHero(tmp2); break; }
	}

	setPlayer(player);
}

void Game::initEnemy() {

	string enemyName = "enemy";

	Player enemy = getPlayer();

	Hero tmp = getEnemy().getPlayerHero();
	tmp = tmp.getHeroById(3);

	enemy.setPlayerHero(tmp);
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
		if (GetAsyncKeyState(VK_ESCAPE) & 1)
		{
			menu();
			break;
		}

		Sleep(100);
	}
}

void Game::settings()
{
	printGameSettings();

	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 1)
		{
			menu();
			break;
		}

		Sleep(100);
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
		if ((GetAsyncKeyState(VK_UP) & 1) || (GetAsyncKeyState(0x57) & 1))
		{
			if (menuIndex == 0) { menuChoice = 0; menuIndex = 0; refreshMenu = true; }
			if (menuIndex == 1) { menuChoice = 1; menuIndex = 0; refreshMenu = true; }
			if (menuIndex == 2) { menuChoice = 2; menuIndex = 1; refreshMenu = true; }
			if (menuIndex == 3) { menuChoice = 3; menuIndex = 2; refreshMenu = true; }

		}

		if ((GetAsyncKeyState(VK_DOWN) & 1) || (GetAsyncKeyState(0x53) & 1))
		{
			if (menuIndex == 3) { menuChoice = 3; menuIndex = 3; refreshMenu = true; }
			if (menuIndex == 2) { menuChoice = 3; menuIndex = 3; refreshMenu = true; }
			if (menuIndex == 1) { menuChoice = 2; menuIndex = 2; refreshMenu = true; }
			if (menuIndex == 0) { menuChoice = 1; menuIndex = 1; refreshMenu = true; }
		}

		if (GetAsyncKeyState(VK_SPACE) & 1)
		{
			system("cls");
			if (menuChoice == 0) { startGame(); }
			if (menuChoice == 1) { shop(); }
			if (menuChoice == 2) { settings(); }
			if (menuChoice == 3) { exit(); }
		}

		if (menuChoice == 0 && refreshMenu)
		{
			refreshMenu = false;
			system("cls");
			printGameLogo();
			setConsoleColor(purpleTextColor);

			coutCentered("> Старт <");
			coutCentered(menuSeparator);

			coutCentered("Магазин");
			coutCentered(menuSeparator);

			coutCentered("Настройки");
			coutCentered(menuSeparator);

			coutCentered("Выход");

			setCursorPosition(consoleHeight, 0);
			cout << "Нажмите пробел для выбора";
		}

		if (menuChoice == 1 && refreshMenu)
		{
			refreshMenu = false;
			system("cls");
			printGameLogo();
			setConsoleColor(purpleTextColor);

			coutCentered("Старт");
			coutCentered(menuSeparator);

			coutCentered("> Магазин <");
			coutCentered(menuSeparator);

			coutCentered("Настройки");
			coutCentered(menuSeparator);

			coutCentered("Выход");

			setCursorPosition(consoleHeight, 0);
			cout << "Нажмите пробел для выбора";
		}

		if (menuChoice == 2 && refreshMenu)
		{
			refreshMenu = false;
			system("cls");
			printGameLogo();
			setConsoleColor(purpleTextColor);

			coutCentered("Старт");
			coutCentered(menuSeparator);

			coutCentered("Магазин");
			coutCentered(menuSeparator);

			coutCentered("> Настройки <");
			coutCentered(menuSeparator);

			coutCentered("Выход");

			setCursorPosition(consoleHeight, 0);
			cout << "Нажмите пробел для выбора";
		}

		if (menuChoice == 3 && refreshMenu)
		{
			refreshMenu = false;
			system("cls");
			printGameLogo();
			setConsoleColor(purpleTextColor);

			coutCentered("Старт");
			coutCentered(menuSeparator);

			coutCentered("Магазин");
			coutCentered(menuSeparator);

			coutCentered("Настройки");
			coutCentered(menuSeparator);

			coutCentered("> Выход <");

			setCursorPosition(consoleHeight, 0);
			cout << "Нажмите пробел для выбора";
		}

	}
}

////////////////// END MENU //////////////////

////////////////// PRINT HEAD //////////////////

void Game::printGameLogo()
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

void Game::printGameBattle()
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

void Game::printGameShop()
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

void Game::printGameSettings()
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

void Game::printGameWin()
{
	setConsoleColor(redTextColor);

	cout << R"(
			 __      __.__      ._.
			/  \    /  \__| ____| |
			\   \/\/   /  |/    \ |
			 \        /|  |   |  \|
			  \__/\  / |__|___|  /_
			       \/          \/\/
)" << '\n';
}

void Game::printGameLose()
{
	setConsoleColor(redTextColor);

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

void Game::printBattle(bool showLogo)
{
	if (showLogo) { setCursorPosition(0, 0); printGameBattle(); }

	printSeparatorForBattle();

	string str1;
	string str2 = " |";

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

	printSeparatorForBattle();

	cout.fill(' ');
	SetConsoleTextAttribute(hConsole, lightGreenTextColor);

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

	str1 = "| Здоровье: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(enemy.getPlayerHero().getHealth());

	cout.width(str2.length());
	cout << str2 << endl;

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

	if (showLogo) { setCursorPosition(consoleHeight, 0); cout << "Q - Атака, W - Лечение"; }
}

void Game::battle()
{
	printBattle(true);

	while (true)
	{
		if (GetAsyncKeyState('Q') & 1) { system("cls"); attack(); }
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

		if (enemyHero.getHealth() <= 0) { printGameWin(); printBattle(false); }
		else { whoAttack = 0; }

		Sleep(1000);

	}
	if (whoAttack == 0) {

		playerHero.setHealth(playerHero.getHealth() - enemyHero.getDamage());
		player.setPlayerHero(playerHero);

		if (playerHero.getHealth() <= 0) { printGameLose(); printBattle(false); }
		else { printBattle(1); }

		Sleep(1000);
	}
}

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

void Game::startGame()
{
	battle();

	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 1) { menu(); break; }
	}
}
