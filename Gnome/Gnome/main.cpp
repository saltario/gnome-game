#include "conio.h"
#include "Functions.h"
#include "Hero.h"
#include "Player.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	Hero hero = getHero(1);
	Hero Luse = getHero(2); 

	printHero(Luse);
	_getch();
	return 0;
}