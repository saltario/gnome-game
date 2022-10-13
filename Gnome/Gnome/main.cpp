#include "conio.h"
#include "Game.h"

using namespace std;

Game game = Game();

void menu();

void startGame()
{
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

int main()
{
	setlocale(LC_ALL, "Rus");

	setWindowAttribute();

	game.initGame();
	menu();

	_getch();
	return 0;
}
