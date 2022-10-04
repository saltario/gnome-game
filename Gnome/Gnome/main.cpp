#include "conio.h"

#include "Game.h"
#include "Hero.h"
#include "Player.h"

using namespace std;

Game game = Game();

Player player = Player();
Player enemy = Player();

Hero playerHero = Hero();
Hero enemyHero = Hero();

void menu();

void printTwoHero(Hero hero1, Hero hero2)
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

void initPlayer() {

	printLogo();

	string playerName = "player";
	string separator = "			  ";

	cout << separator << "Введите имя: ";
	cin >> playerName;
	player.setName(playerName);
}

void initPlayerHero() {

	string separator = "			  ";
	int heroChoice;

	playerHero.setupHero(1);

	printTwoHero(playerHero, playerHero);

	setConsoleColor(redTextColor);
	showConsoleCursor(false);
	coutCentered("Выберите героя");

	while (true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			playerHero.setupHero(1);
			break;
		}

		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			playerHero.setupHero(5);
			break;
		}

		Sleep(100);
	}

	menu();
}

void initEnemy() {

	string enemyName = "enemy";
	enemy.setName(enemyName);
	enemyHero.setupHero(2);

}

void startGame()
{
	printBattle();
	game.printBattle(player, playerHero, enemy, enemyHero);

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

void shop()
{
	printShop();

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

void settings()
{
	printSettings();

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

void exit()
{
	
}

void menu() {

	system("cls");

	printLogo();

	setConsoleColor(purpleTextColor);
	cout.fill(' ');

	string menuSeparator = "-----------";

	coutCentered("Старт");
	coutCentered(menuSeparator);

	coutCentered("Магазин");
	coutCentered(menuSeparator);

	coutCentered("Настройки");
	coutCentered(menuSeparator);

	coutCentered("Выход");

	bool isMenu = true;

	showConsoleCursor(false);

	while (isMenu)
	{
		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			system("cls");
			startGame();
		}

		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			system("cls");
			shop();
		}

		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
		{
			system("cls");
			settings();
		}

		if (GetAsyncKeyState(VK_NUMPAD4) & 1)
		{
			system("cls");
			exit();
			isMenu = false;
		}

		Sleep(100);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	setWindowAttribute();

	initPlayer();
	initPlayerHero();
	initEnemy();

	_getch();
	return 0;
}
