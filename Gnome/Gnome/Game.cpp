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

	SetConsoleTextAttribute(hConsole, lightGreenTextColor);

	cout.fill(' ');
	cout.width(heroTextWidth);
	cout << "Имя: ";
	cout.width(heroTextWidth);
	cout << playerHero.getName();

	printEmptySeparator();

	cout.width(heroTextWidth);
	cout << "Имя: "; 
	cout.width(heroTextWidth);
	cout << enemyHero.getName() << endl;


	cout.width(heroTextWidth);
	cout << "Здоровье: ";
	cout.width(heroTextWidth);
	cout << to_string(playerHero.getHealth());

	printEmptySeparator();

	cout.width(heroTextWidth);
	cout << "Здоровье: ";

	cout.width(heroTextWidth);
	cout << to_string(enemyHero.getHealth()) << endl;

	cout.width(heroTextWidth);
	cout << "Урон: ";
	cout.width(heroTextWidth); 
	cout << to_string(playerHero.getDamage());

	printEmptySeparator();

	cout.width(heroTextWidth);
	cout << "Урон: ";
	cout.width(heroTextWidth);
	cout << to_string(enemyHero.getDamage()) << endl;

	printSeparatorForBattle();
}
