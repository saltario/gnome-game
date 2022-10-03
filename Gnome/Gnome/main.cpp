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

void setWindow() {

	HWND consoleWindow = GetConsoleWindow();
	RECT rect;

	GetWindowRect(consoleWindow, &rect);
	MoveWindow(consoleWindow, rect.left, rect.top, windowHeight, windowWidth, TRUE);
}

int main()
{
	setlocale(LC_ALL, "Rus");

	
	setWindow();
	printLogo();

	//initPlayer();
	//initPlayerHero();
	//initEnemy();

	

	playerHero.setupHero(5);
	enemyHero.setupHero(1);

	game.printBattle(player, playerHero, enemy, enemyHero);
	player.printPlayer();
	playerHero.printHero();

	_getch();
	return 0;
}
