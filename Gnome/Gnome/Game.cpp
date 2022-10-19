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

	int x, y;

	coutCentered("������� ���:      ", false);
	x = 39;
	y = cursorY();

	setCursorPosition(y, x);
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
	coutCentered("�������� �����");

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
		if (GetAsyncKeyState(VK_ESCAPE) & 1) { menu(); break; }
	}
}

void Game::profile()
{
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

			// ����� ������� ������� ����
			if (menuIndex == 0) { menuChoice = menuIndex; }
			else { menuIndex -= 1; menuChoice = menuIndex; }
		}

		if ((GetAsyncKeyState(VK_DOWN) & 1) || (GetAsyncKeyState('S') & 1))
		{
			refreshMenu = true;

			// ����� ������ ������� ����
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

			if (menuChoice == 0) { coutCentered("> ����� <"); }
			else { coutCentered("�����"); }
			coutCentered(menuSeparator);

			if (menuChoice == 1) { coutCentered("> ������� <"); }
			else { coutCentered("�������"); }
			coutCentered(menuSeparator);

			if (menuChoice == 2) { coutCentered("> ������� <"); }
			else { coutCentered("�������"); }
			coutCentered(menuSeparator);

			if (menuChoice == 3) { coutCentered("> ��������� <"); }
			else { coutCentered("���������"); }
			coutCentered(menuSeparator);

			if (menuChoice == 4) { coutCentered("> ����� <"); }
			else { coutCentered("�����"); }
			
			showHelp("������� ������ ��� ������");
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 1) { exit(); break; }
	}
}

////////////////// END MENU //////////////////

////////////////// BATTLE //////////////////

void Game::printBattle(bool showLogo)
{
	if (showLogo) { setCursorPosition(0, 0); printGameBattle(); }

	printSeparatorForBattle();

	string str1;
	string str2 = " |";

	////////////////////////////////
	str1 = "| �����: ";

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
	str1 = "| ���: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << player.getPlayerHero().getName();

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| ���: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << enemy.getPlayerHero().getName();

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| ��������: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(player.getPlayerHero().getHealth());

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| ��������: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(enemy.getPlayerHero().getHealth());

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| ����: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(player.getPlayerHero().getDamage());

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| ����: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(enemy.getPlayerHero().getDamage());

	cout.width(str2.length());
	cout << str2 << endl;

	printSeparatorForBattle();

	if (showLogo) { showHelp("Q - �����, W - �������"); }
}

void Game::battle()
{
	printBattle(true);
	gameOver = false;

	Hero playerHero = Hero();
	playerHero = player.getPlayerHero();

	Hero enemyHero = Hero();
	enemyHero = enemy.getPlayerHero();

	while (true)
	{
		if ((GetAsyncKeyState('Q') & 1) && (gameOver == false)) { system("cls"); attack(); }

		if (GetAsyncKeyState(VK_ESCAPE) & 1) { menu(); break; }

		if (gameOver)
		{
			player.setPlayerHero(playerHero);
			enemy.setPlayerHero(enemyHero);

			if (GetAsyncKeyState(VK_ESCAPE) & 1) { menu(); break; }
		}
	}
}

void Game::attack()
{
	// 1 - � ������
	// 0 - ������� ��������
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
		else { printBattle(1); gameOver = false; }
	}
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

inline void Game::printGameWin()
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

inline void Game::printGameLose()
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

void Game::printTwoHero(Hero hero1, Hero hero2)
{
	printSeparatorForShop();

	string str1;
	string str2 = " |";

	cout.fill(' ');
	SetConsoleTextAttribute(hConsole, lightGreenTextColor);

	////////////////////////////////
	str1 = "| ���: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << hero1.getName();

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| ���: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << hero2.getName();

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| ��������: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(hero1.getHealth());

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| ��������: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(hero2.getHealth());

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| ����: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(hero1.getDamage());

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| ����: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(hero2.getDamage());

	cout.width(str2.length());
	cout << str2 << endl;

	printSeparatorForShop();
}
