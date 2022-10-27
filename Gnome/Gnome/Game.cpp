#include "Game.h"

#define LOGO_POS 0
#define AFTER_LOGO_POS 9
#define PLAYER_POS 9

#define MENU_START_POS 10
#define MENU_PROFILE_POS 12
#define MENU_SHOP_POS 14
#define MENU_SETTINGS_POS 16
#define MENU_EXIT_POS 18

#define HERO_NAME_POS 14
#define HERO_HEALTH_POS 15
#define HERO_DAMAGE_POS 16

#define BTL_MENU_ATTACK_POS 19
#define BTL_MENU_HEALING_POS 21
#define BTL_MENU_NEXT_ENEMY_POS 22

#define STR_OPEN "| "
#define STR_CLOSE " |"
#define STR_OPEN_CLOSE_LNG 2

#define PRINT_STR_CLOSE() {  }

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
			setConsoleColor(menuColor);

			if (menuChoice == 0) { coutCentered("> Старт <"); }
			else { coutCentered("Старт"); }
			printMenuSeparator();

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

	player.savePlayer();
}

void Game::loadGame()
{
	player.loadPlayer();
	player.setPlayerHero(player.getHeroId());
	setPlayer(player);
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

void Game::menu() 
{
	system("cls");
	printGameLogo();

	bool refreshMenu = true;

	int menuIndex = 0;
	int menuChoice = 0;

	while (true)
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
			setConsoleColor(menuColor);

			if (menuChoice == 0) { setCursorPosition(MENU_START_POS); coutCentered("  > Старт <  "); }
			else { setCursorPosition(MENU_START_POS); coutCentered("  Старт  "); }
			printMenuSeparator();

			if (menuChoice == 1) { setCursorPosition(MENU_PROFILE_POS); coutCentered("  > Профиль <  "); }
			else { setCursorPosition(MENU_PROFILE_POS); coutCentered("  Профиль  "); }
			printMenuSeparator();

			if (menuChoice == 2) { setCursorPosition(MENU_SHOP_POS); coutCentered("  > Магазин <  "); }
			else { setCursorPosition(MENU_SHOP_POS); coutCentered("  Магазин  "); }
			printMenuSeparator();

			if (menuChoice == 3) { setCursorPosition(MENU_SETTINGS_POS); coutCentered("  > Настройки <  "); }
			else { setCursorPosition(MENU_SETTINGS_POS); coutCentered("  Настройки  "); }
			printMenuSeparator();

			if (menuChoice == 4) { setCursorPosition(MENU_EXIT_POS); coutCentered("  > Выход <  "); }
			else { setCursorPosition(MENU_EXIT_POS); coutCentered("  Выход  "); }
			
			showHelp("Нажмите пробел для выбора");
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 1) { exit(); break; }
	}
}

////////////////// END MENU //////////////////

////////////////// BATTLE //////////////////

void Game::printBattle(bool showLogo)
{
	if (showLogo) { setCursorPosition(); printGameBattle(); }

	////////////////////////////////
	printPlayer();
	printName();
	printHealth();
	printDamage();
	////////////////////////////////

	if (!showLogo) { showHelp("Нажмите ESC, чтобы продолжить"); }
}

void Game::printPlayer()
{
	string strPres;
	string strValue;

	setCursorPosition(PLAYER_POS);

	printSeparatorForBattle();

	strPres = "Игрок: ";
	strValue = player.getName();

	setConsoleColor(playerFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_OPEN;

	setConsoleColor(heroColor);
	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strPres;

	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strValue;

	setConsoleColor(playerFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_CLOSE;

	printEmptySeparator();

	strValue = enemy.getName();

	setConsoleColor(enemyFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_OPEN;

	setConsoleColor(playerColor);
	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strPres;

	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strValue;

	setConsoleColor(enemyFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_CLOSE << endl;

	////////////////////////////////

	strPres = "Уровень: ";
	strValue = to_string(player.getLevel());

	setConsoleColor(playerFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_OPEN;

	setConsoleColor(heroColor);
	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strPres;

	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strValue;

	setConsoleColor(playerFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_CLOSE;

	printEmptySeparator();

	strValue = to_string(enemy.getLevel());

	setConsoleColor(enemyFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_OPEN;

	setConsoleColor(playerColor);
	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strPres;

	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strValue;

	setConsoleColor(enemyFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_CLOSE << endl;

	////////////////////////////////

	strPres = "Звезды: ";
	strValue = to_string(player.getStars());

	setConsoleColor(playerFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_OPEN;

	setConsoleColor(heroColor);
	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strPres;

	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strValue;

	setConsoleColor(playerFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_CLOSE;

	printEmptySeparator();

	strValue = to_string(enemy.getStars());

	setConsoleColor(enemyFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_OPEN;

	setConsoleColor(playerColor);
	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strPres;

	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strValue;

	setConsoleColor(enemyFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_CLOSE << endl;

	printSeparatorForBattle();
}

void Game::printName()
{
	string strPres = "Имя: ";
	string strValue = player.getPlayerHero().getName();

	setCursorPosition(HERO_NAME_POS);

	setConsoleColor(playerFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_OPEN;

	setConsoleColor(heroColor);
	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strPres;

	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strValue;

	setConsoleColor(playerFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG); 
	cout << STR_CLOSE;

	printEmptySeparator();

	strValue = enemy.getPlayerHero().getName();

	setConsoleColor(enemyFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_OPEN;

	setConsoleColor(playerColor);
	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strPres;

	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strValue;

	setConsoleColor(enemyFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_CLOSE << endl;
}

void Game::printHealth(bool isHeroAttack, bool isEnemyAttack, bool isHeroHealing, bool isEnemyHealing)
{
	string strPres = "Здоровье: ";
	string strValue;

	int strColor;

	setCursorPosition(HERO_HEALTH_POS);

	if (isEnemyAttack)
	{
		strColor = redTextColor;
		strValue = to_string(player.getPlayerHero().getHealth()) + " - (" + to_string(enemy.getPlayerHero().getDamage()) + ")";
	}

	else if (isHeroHealing)
	{
		strColor = greenTextColor;
		strValue = to_string(player.getPlayerHero().getHealth()) + " + (" + to_string(5) + ")";
	}

	else
	{
		strColor = heroColor;
		if (player.getPlayerHero().getHealth() <= 0)
		{
			strValue = to_string(0);
		}
		else
		{
			strValue = to_string(player.getPlayerHero().getHealth());
		}
	}

	setConsoleColor(playerFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_OPEN;

	setConsoleColor(strColor);
	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strPres;

	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strValue;

	setConsoleColor(playerFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_CLOSE;

	printEmptySeparator();

	if (isHeroAttack)
	{
		strColor = redTextColor;
		strValue = to_string(enemy.getPlayerHero().getHealth()) + " - (" + to_string(player.getPlayerHero().getDamage()) + ")";
	}

	else if (isEnemyHealing)
	{
		strColor = greenTextColor;
		strValue = to_string(enemy.getPlayerHero().getHealth()) + " + (" + to_string(5) + ")";
	}

	else
	{
		strColor = heroColor;
		if (enemy.getPlayerHero().getHealth() <= 0)
		{
			strValue = to_string(0);
		}
		else
		{
			strValue = to_string(enemy.getPlayerHero().getHealth());
		}
	}

	setConsoleColor(enemyFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_OPEN;

	setConsoleColor(strColor);
	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strPres;

	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strValue;

	setConsoleColor(enemyFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_CLOSE << endl;
}

void Game::printDamage()
{
	string strPres = "Урон: ";
	string strValue = to_string(player.getPlayerHero().getDamage());

	setCursorPosition(HERO_DAMAGE_POS);

	setConsoleColor(playerFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_OPEN;

	setConsoleColor(heroColor);
	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strPres;

	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strValue;

	setConsoleColor(playerFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_CLOSE;

	printEmptySeparator();

	strValue = to_string(enemy.getPlayerHero().getDamage());

	setConsoleColor(enemyFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_OPEN;

	setConsoleColor(playerColor);
	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strPres;

	cout.width(heroTextWidth - STR_OPEN_CLOSE_LNG);
	cout << strValue;

	setConsoleColor(enemyFrameColor);
	cout.width(STR_OPEN_CLOSE_LNG);
	cout << STR_CLOSE << endl;

	printSeparatorForBattle();
}

void Game::battle()
{
	gameOver = false;
	whoAttack = 1;
	bool nextEnemy = true;

	Hero playerHero = Hero();
	playerHero = player.getPlayerHero();

	Hero enemyHero = Hero();
	enemyHero = enemy.getPlayerHero();

	bool refreshMenu = true;
	bool shortChoice = false;

	int menuIndex = 0;
	int menuChoice = 0;

	int maxCountMenu = 2;

	choiceEnemy();

	while (true)
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
			if (menuIndex == maxCountMenu) { menuChoice = menuIndex; }
			else { menuIndex += 1; menuChoice = menuIndex; }
		}

		if (GetAsyncKeyState('Q') & 1) { shortChoice = true; menuChoice = 0; }
		if (GetAsyncKeyState('E') & 1) { shortChoice = true; menuChoice = 1; }
		if (GetAsyncKeyState('R') & 1) { shortChoice = true; menuChoice = 2; }

		if ((GetAsyncKeyState(VK_SPACE) & 1) || shortChoice)
		{
			if ((menuChoice == 0) && (gameOver == false)) 
			{ 
				nextEnemy = false; 
				maxCountMenu = 1; 

				if (gameOver == false) { playerStep(1, 0); }
				if (gameOver == false) { enemyStep(1, 0); }
			}
			if ((menuChoice == 1) && (gameOver == false)) 
			{ 
				nextEnemy = false; 
				maxCountMenu = 1; 

				if (gameOver == false) { playerStep(0, 1); }
				if (gameOver == false) { enemyStep(0, 1); }
			}

			if ((menuChoice == 2) && (nextEnemy)) { choiceEnemy(); }

			shortChoice = false;
			refreshMenu = true;
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 1) 
		{ 
			if (gameOver == false) { exitBattle(); }
			menu(); 
			break; 
		}

		if (gameOver) { refreshMenu = false; }
		
		if (refreshMenu)
		{
			refreshMenu = false;
			setConsoleColor(menuColor);

			////////////////////////////////

			if (menuChoice == 0) 
			{ 
				printHealth(1, 0, 0, 0);
				setCursorPosition(BTL_MENU_ATTACK_POS);

				setConsoleColor(menuColor); 
				coutCentered("  > Атака <  "); 
			}
			else 
			{ 
				setCursorPosition(BTL_MENU_ATTACK_POS);
				coutCentered("  Атака  "); 
			}

			printMenuSeparator();

			////////////////////////////////

			if (menuChoice == 1) 
			{ 
				printHealth(0, 0, 1, 0);
				setCursorPosition(BTL_MENU_ATTACK_POS);
				setConsoleColor(menuColor); 
				coutCentered("  Атака  ");
				printMenuSeparator();
				coutCentered("  > Лечение <  "); 
			}
			else 
			{ 
				setCursorPosition(BTL_MENU_HEALING_POS);
				coutCentered("  Лечение  "); 
			}

			////////////////////////////////

			if (nextEnemy) 
			{
				setCursorPosition(BTL_MENU_NEXT_ENEMY_POS);
				printMenuSeparator();

				if (menuChoice == 2) 
				{ 
					printHealth(0, 0, 0, 0);
					setCursorPosition(BTL_MENU_NEXT_ENEMY_POS);
					printMenuSeparator();
					coutCentered("  > Следующий <  "); 
				}
				else { coutCentered("  Следующий  "); }
			}
			else
			{
				setCursorPosition(BTL_MENU_NEXT_ENEMY_POS);
				coutCentered("           ");
				coutCentered("             ");
			}

			showHelp("Нажмите пробел для выбора");
		}
	}
}

void Game::playerStep(bool attack, bool healing)
{
	Hero playerHero = Hero();
	playerHero = player.getPlayerHero();

	Hero enemyHero = Hero();
	enemyHero = enemy.getPlayerHero();

	if (attack)
	{
		enemyHero.setHealth(enemyHero.getHealth() - playerHero.getDamage());
		enemy.setPlayerHero(enemyHero);

		if (enemyHero.getHealth() <= 0) { gameOver = true; gameWin(); }
		else { printHealth(1, 0, 0, 0); Sleep(1000); whoAttack = 0; gameOver = false; }
	}

	if (healing)
	{
		playerHero.setHealth(playerHero.getHealth() + 5);
		player.setPlayerHero(playerHero);

		printHealth(0, 0, 1, 0); Sleep(1000); whoAttack = 0; gameOver = false;
	}
}

void Game::enemyStep(bool attack, bool healing)
{
	Hero playerHero = Hero();
	playerHero = player.getPlayerHero();

	Hero enemyHero = Hero();
	enemyHero = enemy.getPlayerHero();

	if (attack)
	{
		playerHero.setHealth(playerHero.getHealth() - enemyHero.getDamage());
		player.setPlayerHero(playerHero);

		if (playerHero.getHealth() <= 0) { gameOver = true; gameLose(); }
		else { printHealth(0, 1, 0, 0); Sleep(1000); whoAttack = 1; gameOver = false; }
	}

	if (healing)
	{
		enemyHero.setHealth(enemyHero.getHealth() + 5);
		enemy.setPlayerHero(enemyHero);

		printHealth(0, 0, 0, 1); Sleep(1000); whoAttack = 1; gameOver = false;
	}
}

void Game::gameWin()
{
	player.setLevel(player.getLevel() + 1);
	player.setStars(player.getStars() + 10);
	setPlayer(player);
	player.savePlayer();

	printGameWin(); 
	printBattle(false);

	endBattle();
}

void Game::gameLose()
{
	player.setLevel(player.getLevel() - 1);
	player.setStars(player.getStars() - 10);
	setPlayer(player);
	player.savePlayer();

	printGameLose(); 
	printBattle(false);

	endBattle();
}

void Game::choiceEnemy()
{
	srand(time(0));
	int random = 1 + rand() % 6;

	enemy.setEnemy();
	enemy.setPlayerHero(random);

	setEnemy(enemy);
	printBattle();
}

void Game::endBattle()
{
	player.setPlayerHero(player.getHeroId());
	enemy.setPlayerHero(enemy.getHeroId());
}

void Game::exitBattle()
{
	gameOver = true;

	player.setLevel(player.getLevel() - 1);
	player.setStars(player.getStars() - 10);
	setPlayer(player);
	player.savePlayer();

	endBattle();
}

////////////////// END BATTLE //////////////////

inline void Game::printMenuSeparator()
{
	string menuSeparator = "-----------";
	setConsoleColor(menuSeparatorColor);
	coutCentered(menuSeparator);
	setConsoleColor(menuColor);
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

void Game::showHelp(string helpText)
{
	setConsoleColor(helpColor);
	setCursorPosition(consoleHeight);
	coutCentered(helpText, 0);
}

////////////////// PRINT HEAD //////////////////

inline void Game::printGameLogo()
{
	setConsoleColor(logoColor);

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
	setConsoleColor(logoColor);

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
	setConsoleColor(logoColor);

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
	setConsoleColor(logoColor);

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
	setConsoleColor(logoColor);

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
	setConsoleColor(gameWinColor);
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
	setConsoleColor(gameLoseColor);
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
