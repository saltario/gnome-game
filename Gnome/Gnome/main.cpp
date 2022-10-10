#include "conio.h"
#include "Game.h"

using namespace std;

Game game = Game();
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

	Player player = Player();

	string playerName = "player";
	string separator = "			  ";

	cout << separator << "Введите имя: ";
	cin >> playerName;

	player.setName(playerName);
	game.setPlayer(player);
}

void initPlayerHero() {

	string separator = "			  ";

	Hero tmp1 = Hero();
	tmp1 = tmp1.getHeroById(1);

	Hero tmp2 = Hero();
	tmp2 = tmp2.getHeroById(5);

	Player player = game.getPlayer();

	printTwoHero(tmp1, tmp2);

	setConsoleColor(redTextColor);
	showConsoleCursor(false);
	coutCentered("Выберите героя");

	while (true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			player.setPlayerHero(1);
			game.setPlayer(player);
			break;
		}

		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			player.setPlayerHero(5);
			game.setPlayer(player);
			break;
		}

		Sleep(100);
	}

	menu();
}

void initEnemy() {

	string enemyName = "enemy";
	game.getEnemy().setName(enemyName);
	game.getEnemy().setPlayerHero(3);
}

void startGame()
{
	system("cls");
	printBattle();
	game.printBattle();

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

void initGame() {

	printLogo();

	initPlayer();
	initEnemy();
	initPlayerHero();
}

int main()
{
	setlocale(LC_ALL, "Rus");

	setWindowAttribute();
	initGame();

	_getch();
	return 0;
}
