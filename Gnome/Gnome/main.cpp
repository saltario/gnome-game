#include "conio.h"
#include "Game.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	setWindowAttribute();

	Game game = Game();
	game.initGame();
	game.menu();

	_getch();
	return 0;
}
