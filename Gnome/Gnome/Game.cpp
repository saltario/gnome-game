#include "Game.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::printBattle(Player player, Hero playerHero, Player enemy, Hero enemyHero)
{
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
	cout << playerHero.getName();

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| Имя: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << enemyHero.getName();

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| Здоровье: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(playerHero.getHealth());

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| Здоровье: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(enemyHero.getHealth());

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| Урон: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(playerHero.getDamage());

	cout.width(str2.length());
	cout << str2;

	printEmptySeparator();

	str1 = "| Урон: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(enemyHero.getDamage());

	cout.width(str2.length());
	cout << str2 << endl;

	printSeparatorForBattle();
}
