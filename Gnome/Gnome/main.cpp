#include "conio.h"

#include "Game.h"
#include "Hero.h"
#include "Player.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	string playerName = "player";
	string enemyName = "enemy";

	Hero playerHero = Hero();
	Hero enemyHero = Hero();

	cout << "Введите имя: ";
	cin >> playerName;
	Player player(playerName);

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

	Player enemy(enemyName);
	enemyHero.setupHero(2);

	Game game = Game();
	game.printBattle(player, playerHero, enemy, enemyHero);

	_getch();
	return 0;
}
