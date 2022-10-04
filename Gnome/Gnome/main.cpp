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

void initPlayer() {

	string playerName = "player";

	cout << "Введите имя: ";
	cin >> playerName;
	player.setName(playerName);

}

void initPlayerHero() {

	int heroChoice;

	playerHero.setupHero(1);
	playerHero.printHero();

	playerHero.setupHero(5);
	playerHero.printHero();

	cout << "Выберите героя: ";
	cin >> heroChoice;

	if (heroChoice == 1) {
		playerHero.setupHero(1);
		playerHero.printHero();
	}
	else if (heroChoice == 2)
	{
		playerHero.setupHero(5);
		playerHero.printHero();
	}

	system("cls");

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
}

void shop()
{
	printShop();
}

void settings()
{
	printSettings();
}

void exit()
{
	
}

void menu() {

	SetConsoleTextAttribute(hConsole, purpleTextColor);
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
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			system("cls");
			startGame();
		}

		if (GetAsyncKeyState(VK_NUMPAD2))
		{
			system("cls");
			shop();
		}

		if (GetAsyncKeyState(VK_NUMPAD3))
		{
			system("cls");
			settings();
		}

		if (GetAsyncKeyState(VK_NUMPAD4))
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
	printLogo();

	//initPlayer();
	//initPlayerHero();
	//initEnemy();
	
	playerHero.setupHero(5);
	enemyHero.setupHero(1);

	
	menu();

	_getch();
	return 0;
}
